/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:21:04 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/15 18:50:14 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	draw_line(t_img *img, t_line *line)
{
	int		y;

	if (line->start < 0)
		line->start = 0;
	if (line->end >= WIN_H)
		line->end = WIN_H - 1;
	y = line->start;
	while (y <= line->end)
	{
		img->data[y * WIN_W + line->x] = line->color;
		y++;
	}
}

void	render_frame(t_game *g)
{
	int		x;
	t_ray	r;
	t_wall	wall;

	x = 0;
	while (x < WIN_H)
	{
		update_ray_direction(&g->pla, x, &r);
		update_ray_position(&g->pla, &r);
		r.side = handle_dda(g, &r);
		calculate_wall_distance(&g->pla, &r);
		calculate_wall_parameters(&wall, &r);
		draw_walls(g, x, &r, &wall);
		x++;
	}
	mlx_put_image_to_window(g->win.mlx_p, g->win.win_p, g->win.img.img_ptr,
		0, 0);
}
