/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:21:04 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/17 02:33:50 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
