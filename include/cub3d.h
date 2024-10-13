/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:56:18 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/12 14:18:02 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "structs.h"
# include "keys.h"
# include "../lib/minilibx/mlx.h"
# include "../lib/libft/libft.h"

// Definiciones de macros
# define WIN_W 640
# define WIN_H 640
# define TEX_W 32
# define TEX_H 32

// Prototipos de funciones en cleanup.c
void	free_map(t_game *g);
void	free_window(t_game *g);
void	exit_game(t_game *g, const char *msg);

// Prototipos de funciones en events.c
int		handle_keypress(int keycode, t_game *g);
int		handle_keyrelease(int keycode, t_game *g);
int		close_window(t_game *g);

// Prototipos de funciones en init.c
void	init_game(t_game *g);
void	init_window(t_game *g);

// Prototipos de funciones en movement.c
void	move_player(t_game *g, int dir);
void	strafe_player(t_game *g, int dir);
void	rotate_player(t_game *g, double angle);

// Prototipos de funciones en parse_map.c
void	parse_map(t_game *g, const char *filename);

// Prototipos de funciones en render.c
void	render_frame(t_game *g);
void	draw_line(t_img *img, t_line *line);

// Prototipos de funciones en textures.c
void	load_textures(t_game *g);
void	free_textures(t_game *g);

#endif
