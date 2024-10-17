/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:21:04 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/16 23:57:54 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
}
