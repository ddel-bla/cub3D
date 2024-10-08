/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:11:55 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/08 14:50:50 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	mlx_hook(game.win.win_p, 17, 1L << 17, close_window, &game);
	mlx_loop(game.win.mlx_p);
	exit_game(&game, NULL);
	return (EXIT_SUCCESS);
}
