/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r < cfeliz-r@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:35:17 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/10/21 10:55:04 by cfeliz-r         ###   ########.fr       */
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

static char	*replace_spaces(const char *line, int target_length)
{
	char	*new_line;
	int		i;

	new_line = malloc(target_length + 1);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < target_length)
	{
		if (i < ft_strlen(line))
		{
			if (ft_isspace(line[i]))
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
	return (new_line);
}

static void	allocate_map_grid(t_game *game, char **lines, int start_index)
{
	int		i;
	char	*modified_line;

	game->map.grid = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.grid)
		exit_game(game, "Error: Unable to allocate memory for map grid.");
	i = 0;
	while (i < game->map.height)
	{
		modified_line = replace_spaces(lines[start_index + i], game->map.width);
		if (!modified_line)
			exit_game(game, "Error: allocate memory for map row.");
		game->map.grid[i] = modified_line;
		i++;
	}
	game->map.grid[game->map.height] = NULL;
}

static void	load_map(t_game *game, char **lines, int start_index)
{
	int	i;
	int	max_length;
	int	length;

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
	allocate_map_grid(game, lines, start_index);
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
	i = -1;
	while (lines[++i] != NULL)
	{
		if (game->control_flags == 2)
			break ;
		parse_textures(game, lines[i]);
	}
	if (game->control_flags != 2 || game->ceiling == -1 || game->floor == -1)
		exit_game(game, "Error: Missing identifiers in .cub file.");
	load_map(game, lines, i);
	if (validate_map(game) == 0)
		exit_game(game, "Error: Invalid map.");
	free(content);
	clean_split(lines);
}
