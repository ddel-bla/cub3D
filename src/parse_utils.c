/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r < cfeliz-r@student.42madrid.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-11 12:30:24 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024-10-11 12:30:24 by cfeliz-r         ###   ########.42madri  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	is_valid_char(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == ' ' || c == '\n');
}

int	is_border(int i, int j, t_map *map)
{
	return (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1);
}

int	check_map_grid(t_game *game, int *player_x, int *player_y)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (!is_valid_char(game->map.grid[i][j]))
				return (0);
			if (is_border(i, j, &game->map) && game->map.grid[i][j] != '1')
				return (0);
			if (game->map.grid[i][j] == 'N' || game->map.grid[i][j] == 'S'
				|| game->map.grid[i][j] == 'W' || game->map.grid[i][j] == 'E')
			{
				*player_x = j;
				*player_y = i;
				find_player(game, i, j);
			}
			j++;
		}
		i++;
	}
	return (1);
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
	if (game->pla.flag_player != 1)
		exit_game(game, "Error: multiple players.");
	return (1);
}

int	parse_color(char *str)
{
	int	r;
	int	g;
	int	b;

	if (!ft_isdigit(*str))
		return (-1);
	r = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str++ != ',' || !ft_isdigit(*str))
		return (-1);
	g = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str++ != ',' || !ft_isdigit(*str))
		return (-1);
	b = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0' || r < 0 || r > 255
		|| g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (r << 16 | g << 8 | b);
}
