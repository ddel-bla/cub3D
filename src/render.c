/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:21:04 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/12 17:47:24 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	get_wall_color(t_ray *r)
{
	if (r->side == 0)
		return (0xFF0000);
	return (0x00FF00);
}

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

void	draw_walls(t_game *g, int x, t_ray *r, t_wall *wall)
{
	t_line	line;

	line.x = x;
	line.start = wall->draw_start;
	line.end = wall->draw_end;
	line.color = get_wall_color(r);
	draw_line(&g->win.img, &line);
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
	{
		r->perp_w_d = r->map_x - p->pos_x + (1 - r->step_x) / 2;
		r->perp_w_d /= r->ray_dir_x;
	}
	else
	{
		r->perp_w_d = r->map_y - p->pos_y + (1 - r->step_y) / 2;
		r->perp_w_d /= r->ray_dir_y;
	}
}

int	perform_dda(t_game *g, t_ray *r, double delta_dist_x, double delta_dist_y)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (r->map_x < 0 || r->map_x >= g->map.width)
			return (1);
		if (r->map_y < 0 || r->map_y >= g->map.height)
			return (1);
		if (g->map.grid[r->map_y][r->map_x] == '1')
			hit = 1;
	}
	return (r->side);
}

int	handle_dda(t_game *g, t_ray *r)
{
	double	delta_dist_x;
	double	delta_dist_y;

	delta_dist_x = fabs(1 / r->ray_dir_x);
	delta_dist_y = fabs(1 / r->ray_dir_y);
	return (perform_dda(g, r, delta_dist_x, delta_dist_y));
}

void	calc_step_dist(t_player *p, t_ray *r,
		double delta_dist_x, double delta_dist_y)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (p->pos_x - r->map_x) * delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - p->pos_x) * delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (p->pos_y - r->map_y) * delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - p->pos_y) * delta_dist_y;
	}
}

void	update_ray_position(t_player *p, t_ray *r)
{
	double	delta_dist_x;
	double	delta_dist_y;

	r->map_x = (int)p->pos_x;
	r->map_y = (int)p->pos_y;
	delta_dist_x = fabs(1 / r->ray_dir_x);
	delta_dist_y = fabs(1 / r->ray_dir_y);
	calc_step_dist(p, r, delta_dist_x, delta_dist_y);
}

void	update_ray_direction(t_player *p, int x, t_ray *r)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_W - 1;
	r->ray_dir_x = p->dir_x + p->plane_x * camera_x;
	r->ray_dir_y = p->dir_y + p->plane_y * camera_x;
}

void	render_frame(t_game *g)
{
	int		x;
	t_ray	r;
	t_wall	wall;

	x = 0;
	while (x < WIN_W)
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
