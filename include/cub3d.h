/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:56:18 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/17 01:04:53 by ddel-bla         ###   ########.fr       */
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
# define TEX_W 64
# define TEX_H 64
# define SCALE 10

// Prototipos de funciones en cleanup.c
void	free_map(t_game *g);
void	free_window(t_game *g);
void	exit_game(t_game *g, const char *msg);

// Prototipos de funciones en draw_minimap.c
void	draw_minimap(t_game *g);

// Prototipos de funciones en events.c
int		handle_keypress(int keycode, t_game *g);
int		handle_mouse_move(int x, int y, t_game *g);
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

// Prototipos de funciones en render_dda.c
int		handle_dda(t_game *g, t_ray *r);

// Prototipos de funciones en render_ray.c
void	update_ray_position(t_player *p, t_ray *r);
void	update_ray_direction(t_player *p, int x, t_ray *r);

// Prototipos de funciones en render_walls.c
void	draw_walls(t_game *g, int x, t_ray *r, t_wall *wall);
void	calculate_wall_parameters(t_wall *wall, t_ray *r);
void	calculate_wall_distance(t_player *p, t_ray *r);

// Prototipos de funciones en render.c
void	render_frame(t_game *g);

// Prototipos de funciones en textures.c
void	load_textures(t_game *g);
void	free_textures(t_game *g);

#endif
