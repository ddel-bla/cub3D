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

int	is_player_surrounded(t_map *map, int player_x, int player_y)
{
	if (map->grid[player_y - 1][player_x] != '1' ||
		map->grid[player_y + 1][player_x] != '1' ||
		map->grid[player_y][player_x - 1] != '1' ||
		map->grid[player_y][player_x + 1] != '1')
		return (1);
	return (0);
}

int	is_valid_char(char c)
{
	return (c == '1' || c == '0' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == ' ');
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
			if (!is_valid_char(game->map.grid[i][j])
			|| (is_border(i, j, &game->map) && game->map.grid[i][j] != '1'))
				return (0);
			if (game->map.grid[i][j] == 'N' || game->map.grid[i][j] == 'S' ||
				game->map.grid[i][j] == 'W' || game->map.grid[i][j] == 'E')
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
