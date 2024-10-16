/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:35:17 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/10/15 15:53:25 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static char	*read_file(const char *filename)
{
	int		fd;
	char	*line;
	char	*content;
	char	*temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = ft_strdup("");
	if (!content)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strjoin(content, line);
		free(content);
		content = temp;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (content);
}

static char *replace_spaces_with_one(const char *line, int target_length)
{
	char *new_line;
	int i;

	new_line = malloc(target_length + 1);
	if (!new_line)
		return NULL;
	i = 0;
	while (i < target_length)
	{
		if (i < ft_strlen(line))
		{
			if (line[i] == ' ')
				new_line[i] = '1';
			else
				new_line[i] = line[i];
		}
		else
		{
			new_line[i] = '1';
		}
		i++;
	}
	new_line[target_length] = '\0';

	return new_line;
}

static void load_map(t_game *game, char **lines, int start_index)
{
    int i;
    int max_length;
    int length;
	char *modified_line;

    while (lines[start_index + game->map.height] != NULL)
        game->map.height++;
    max_length = 0;
    i = start_index;
    while (i < start_index + game->map.height)
    {
        length = ft_strlen(lines[i]);
        if (length > max_length)
            max_length = length;
        i++;
    }
    game->map.width = max_length;
    game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
    if (!game->map.grid)
        exit_game(game, "Error: Unable to allocate memory for map grid.");
    i = 0;
    while (i < game->map.height)
    {
        modified_line = replace_spaces_with_one(lines[start_index + i], game->map.width);
        if (!modified_line)
            exit_game(game, "Error: Unable to allocate memory for modified map row.");
        game->map.grid[i] = modified_line;
        i++;
    }
    game->map.grid[game->map.height] = NULL;
}

int	validate_map(t_game *game)
{
	int	player_x;
	int	player_y;

	player_x = -1;
	player_y = -1;
	if (check_map_grid(game, &player_x, &player_y) == 0)
		return (0);
	if (player_x == -1 || player_y == -1)
		exit_game(game, "Error: Player not found in the map.");
	return (1);
}
void print_map(t_game *game)
{
	int i = 0;
	while (i < game->map.height)
	{
		printf("%s\n", game->map.grid[i]);
		i++;
	}
}
void	parse_map(t_game *game, const char *filename)
{
	char	*content;
	char	**lines;
	int		i;

	content = read_file(filename);
	if (!content)
		exit_game(game, "Error: Unable to read map file.");
	lines = ft_split(content, '\n');
	i = 0;
	while (lines[i] != NULL)
	{
		if (game->control_flags == 1)
			break;
		parse_textures(game, lines[i]);
		i++;
	}
	load_map(game, lines, i);
	print_map(game);
	if (validate_map(game) == 0)
		exit_game(game, "Error: Invalid map.");
	if (game->player.flag_player != 1)
		exit_game(game, "Error: multiple players.");
	free(content);
	clean_split(lines);
}
