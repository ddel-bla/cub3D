/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_dda.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:21:04 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/16 13:07:25 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
