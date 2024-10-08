/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:10:32 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/08 14:54:07 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_game(t_game *g)
{
	g->win.mlx_p = NULL;
	g->win.win_p = NULL;
	g->win.img.img_ptr = NULL;
	g->win.img.data = NULL;
	g->pla.pos_x = 0;
	g->pla.pos_y = 0;
	g->pla.dir_x = -1;
	g->pla.dir_y = 0;
	g->pla.plane_x = 0;
	g->pla.plane_y = 0.66;
	g->pla.move_speed = 0.05;
	g->pla.rot_speed = 0.03;
	g->map.grid = NULL;
	g->textures = NULL;
}

void	init_window(t_game *g)
{
	g->win.mlx_p = mlx_init();
	if (!g->win.mlx_p)
		exit_game(g, "Error: Unable to initialize MLX.");
	g->win.win_p = mlx_new_window(g->win.mlx_p, WIN_W, WIN_H, "Cub3D");
	if (!g->win.win_p)
		exit_game(g, "Error: Unable to create window.");
	g->window.img.img_ptr = mlx_new_image(g->win.mlx_p, WIN_W, WIN_H);
	if (!g->window.img.img_ptr)
		exit_game(g, "Error: Unable to create image.");
	g->window.img.data = (int *)mlx_get_data_addr(g->window.img.img_ptr,
			&g->window.img.bpp,
			&g->window.img.size_line,
			&g->window.img.endian);
	if (!g->window.img.data)
		exit_game(g, "Error: Unable to get image data address.");
}
