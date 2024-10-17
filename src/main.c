/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:11:55 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/17 01:02:26 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	game_loop(t_game *g)
{
	usleep(50);
	render_frame(g);
	draw_minimap(g);
	mlx_put_image_to_window(g->win.mlx_p, g->win.win_p, g->win.img.img_ptr,
		0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map_file.cub>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	init_game(&game);
	parse_map(&game, argv[1]);
	init_window(&game);
	load_textures(&game);
	mlx_hook(game.win.win_p, 2, 1L << 0, handle_keypress, &game);
	//mlx_hook(game.win.win_p, 6, 1L << 6, handle_mouse_move, &game);
	mlx_hook(game.win.win_p, 17, 1L << 17, close_window, &game);
	mlx_loop_hook(game.win.mlx_p, game_loop, &game);
	mlx_loop(game.win.mlx_p);
	exit_game(&game, NULL);
	return (EXIT_SUCCESS);
}
