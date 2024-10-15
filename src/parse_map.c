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

void	clean_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static void	load_map(t_game *game, char *content)
{
	char	**lines;
	int		i;

	i = 0;

	lines = ft_split(content, '\n');
	game->map.height = 0;
	while (lines[game->map.height])
		game->map.height++;
	game->map.width = ft_strlen(lines[0]);
	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		exit_game(game, "Error: Unable to allocate memory for map grid.");
	while (i < game->map.height)
	{
		game->map.grid[i] = ft_strdup(lines[i]);
		if (!game->map.grid[i])
			exit_game(game, "Error: Unable to allocate memory for map row.");
		i++;
	}
	game->map.grid[game->map.height] = NULL;
	clean_split(lines);
}

int	validate_map(t_game *game)
{
	int	player_x;
	int	player_y;

	player_x = -1;
	player_y = -1;
	if (check_map_grid(game, &player_x, &player_y) == 0)
		return (0);
	exit(0);
	if (player_x == -1 || player_y == -1)
		exit_game(game, "Error: Player not found in the map.");
	if (!is_player_surrounded(&game->map, player_x, player_y))
		exit_game(game, "Error: Player is surrounded by walls.");
	return (1);
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
		if(game->control_flags == 1)
			break;
		parse_textures(game, lines[i]);
		i++;
	}
	load_map(game, lines[i]);
	if (validate_map(game) == 0)
		exit_game(game, "Error: Invalid map.");
	if (game->player.flag_player != 1)
		exit_game(game, "Error: multiple players.");
	free(content);
}

