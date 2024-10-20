/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r < cfeliz-r@student.42madrid.com>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-10-11 11:22:38 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024-10-11 11:22:38 by cfeliz-r         ###   ########.42madri  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	set_player_direction_ew(t_game *game, char dir)
{
	if (dir == 'N')
	{
		game->pla.dir_x = 0;
		game->pla.dir_y = -1;
		game->pla.plane_x = 0.66;
		game->pla.plane_y = 0;
	}
	else if (dir == 'S')
	{
		game->pla.dir_x = 0;
		game->pla.dir_y = 1;
		game->pla.plane_x = -0.66;
		game->pla.plane_y = 0;
	}
}

static void	set_player_direction(t_game *game, char dir)
{
	if (dir == 'W')
	{
		game->pla.dir_x = -1;
		game->pla.dir_y = 0;
		game->pla.plane_x = 0;
		game->pla.plane_y = -0.66;
	}
	else if (dir == 'E')
	{
		game->pla.dir_x = 1;
		game->pla.dir_y = 0;
		game->pla.plane_x = 0;
		game->pla.plane_y = 0.66;
	}
	else
	{
		set_player_direction_ew(game, dir);
	}
	game->pla.flag_player++;
}

void	find_player(t_game *game, int i, int j)
{
	game->pla.pos_x = j + 0.5;
	game->pla.pos_y = i + 0.5;
	set_player_direction(game, game->map.grid[i][j]);
}
