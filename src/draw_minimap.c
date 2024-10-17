/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:21:04 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/17 01:10:46 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_square(t_game *g, int x_start, int y_start, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCALE)
	{
		x = 0;
		while (x < SCALE)
		{
			g->win.img.data[(y_start + y) * WIN_W + (x_start + x)] = color;
			x++;
		}
		y++;
	}
}

void	draw_map_cells(t_game *g)
{
	int	map_x;
	int	map_y;

	map_y = 0;
	while (map_y < g->map.height)
	{
		map_x = 0;
		while (map_x < g->map.width)
		{
			if (g->map.grid[map_y][map_x] == '1')
				draw_square(g, map_x * SCALE, map_y * SCALE, 0xFFFFFF);
			else
				draw_square(g, map_x * SCALE, map_y * SCALE, 0x000000);
			map_x++;
		}
		map_y++;
	}
}

void	draw_player_position(t_game *g)
{
	int	player_x;
	int	player_y;

	player_x = (int)(g->pla.pos_x * SCALE);
	player_y = (int)(g->pla.pos_y * SCALE);
	draw_square(g, player_x, player_y, 0xFF0000);
}

void	draw_minimap(t_game *g)
{
	draw_map_cells(g);
	draw_player_position(g);
}
