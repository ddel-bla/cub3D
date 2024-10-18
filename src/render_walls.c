/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:21:04 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/18 13:40:37 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double	get_wall_x(t_game *g, t_ray *r)
{
	double	wall_x;

	if (r->side == 0)
		wall_x = g->pla.pos_y + r->perp_w_d * r->ray_dir_y;
	else
		wall_x = g->pla.pos_x + r->perp_w_d * r->ray_dir_x;
	wall_x -= floor(wall_x);
	return (wall_x);
}

int	get_wall_color(t_game *g, t_ray *r, t_wall *wall, int y)
{
	int		tex_x;
	int		tex_y;
	double	wall_x;
	int		*texture;

	texture = select_texture(g, r);
	wall_x = get_wall_x(g, r);
	tex_x = (int)(wall_x * (double)TEX_W);
	if ((r->side == 0 && r->ray_dir_x > 0)
		|| (r->side == 1 && r->ray_dir_y < 0))
		tex_x = TEX_W - tex_x - 1;
	if (tex_x < 0)
		tex_x = 0;
	else if (tex_x >= TEX_W)
		tex_x = TEX_W - 1;
	tex_y = (int)(((y - wall->draw_start) * TEX_H) / wall->line_height);
	if (tex_y < 0)
		tex_y = 0;
	else if (tex_y >= TEX_H)
		tex_y = TEX_H - 1;
	if (r->perp_w_d < 1)
		tex_y *= 1 / r->perp_w_d;
	return (texture[TEX_W * tex_y + tex_x]);
}

void	draw_walls(t_game *g, int x, t_ray *r, t_wall *wall)
{
	int	y;
	int	color;

	y = 0;
	while (y < wall->draw_start)
	{
		g->win.img.data[y * WIN_W + x] = g->ceiling;
		y++;
	}
	while (y <= wall->draw_end)
	{
		color = get_wall_color(g, r, wall, y);
		g->win.img.data[y * WIN_W + x] = color;
		y++;
	}
	while (y < WIN_H)
	{
		g->win.img.data[y * WIN_W + x] = g->floor;
		y++;
	}
}

void	calculate_wall_parameters(t_wall *wall, t_ray *r)
{
	wall->line_height = (int)(WIN_H / r->perp_w_d);
	wall->draw_start = -wall->line_height / 2 + WIN_H / 2;
	if (wall->draw_start < 0)
		wall->draw_start = 0;
	wall->draw_end = wall->line_height / 2 + WIN_H / 2;
	if (wall->draw_end >= WIN_H)
		wall->draw_end = WIN_H - 1;
}

void	calculate_wall_distance(t_player *p, t_ray *r)
{
	if (r->side == 0)
		r->perp_w_d = (r->map_x - p->pos_x + (1 - r->step_x) / 2)
			/ r->ray_dir_x;
	else
		r->perp_w_d = (r->map_y - p->pos_y + (1 - r->step_y) / 2)
			/ r->ray_dir_y;
	if (r->perp_w_d <= 0.0001)
		r->perp_w_d = 0.0001;
}
