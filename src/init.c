/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:10:32 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/15 18:17:17 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void init_game(t_game *game)
{
    game->win.mlx_p = NULL;
    game->win.win_p = NULL;
    game->win.img.img_ptr = NULL;
    game->win.img.data = NULL;
    game->pla.pos_x = 0;
    game->pla.pos_y = 0;
    game->pla.dir_x = 0.0;
    game->pla.dir_y = 1.0;
    game->pla.plane_x = 0;
    game->pla.plane_y = 0.66;
    game->pla.move_speed = 0.05;
    game->pla.rot_speed = 0.03;
    game->pla.flag_player = 0;
    game->map.grid = NULL;
    game->ceiling = 0;
	game->floor = 0;
    game->no = (int *)malloc(sizeof(int) * (TEX_W * TEX_H));
	game->so = (int *)malloc(sizeof(int) * (TEX_W * TEX_H));
	game->ea = (int *)malloc(sizeof(int) * (TEX_W * TEX_H));
	game->we = (int *)malloc(sizeof(int) * (TEX_W * TEX_H));
    ft_bzero(&game->texture_paths, sizeof(t_textures));
    ft_memset(&game->map, 0, sizeof(t_map));
}

void	init_window(t_game *g)
{
	g->win.mlx_p = mlx_init();
	if (!g->win.mlx_p)
		exit_game(g, "Error: Unable to initialize MLX.");
	g->win.win_p = mlx_new_window(g->win.mlx_p, WIN_W, WIN_H, "Cub3D");
	if (!g->win.win_p)
		exit_game(g, "Error: Unable to create window.");
	g->win.img.img_ptr = mlx_new_image(g->win.mlx_p, WIN_W, WIN_H);
	if (!g->win.img.img_ptr)
		exit_game(g, "Error: Unable to create image.");
	g->win.img.data = (int *)mlx_get_data_addr(g->win.img.img_ptr,
			&g->win.img.bpp,
			&g->win.img.size_line,
			&g->win.img.endian);
	if (!g->win.img.data)
		exit_game(g, "Error: Unable to get image data address.");
}
