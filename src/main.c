/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:38:36 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/10/18 13:43:55 by cfeliz-r         ###   ########.fr       */
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

int	check_is_ber(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strcmp(file + len - 5, "/.cub") == 0)
		return (0);
	if (ft_strcmp(file + len - 4, ".cub") != 0)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		return (EXIT_FAILURE);
	}
	if (check_is_ber(argv[1]) == 0)
		return (printf("Error File is not a .cub file\n"), 1);
	init_game(&game);
	parse_map(&game, argv[1]);
	init_window(&game);
	load_textures(&game);
	mlx_hook(game.win.win_p, 2, 1L << 0, handle_keypress, &game);
	mlx_hook(game.win.win_p, 6, 1L << 6, handle_mouse_move, &game);
	mlx_hook(game.win.win_p, 17, 1L << 17, close_window, &game);
	mlx_loop_hook(game.win.mlx_p, game_loop, &game);
	mlx_loop(game.win.mlx_p);
	exit_game(&game, NULL);
	return (EXIT_SUCCESS);
}
