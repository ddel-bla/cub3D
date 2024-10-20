/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 15:58:18 by cfeliz-r          #+#    #+#             */
/*   Updated: 2024/10/18 20:15:04 by ddel-bla         ###   ########.fr       */
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
# define WIN_W 800
# define WIN_H 800
# define TEX_W 64
# define TEX_H 64
# define SCALE 10

// Prototipos de funciones en cleanup.c
void	free_map(t_game *g);
void	free_window(t_game *g);
void	exit_game(t_game *g, const char *msg);

// draw_minimap.c
void	draw_minimap(t_game *g);
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
int		*select_texture(t_game *g, t_ray *r);

// Prototipos de funciones en init.c
void	init_game(t_game *game);
void	init_window(t_game *game);

// Prototipos de funciones en events.c
int		handle_keypress(int keycode, t_game *game);
int		handle_keyrelease(int keycode, t_game *game);
int		close_window(t_game *game);
int		handle_mouse_move(int x, int y, t_game *g);

// Prototipos de funciones en movement.c
void	move_player(t_game *game, int direction);
void	strafe_player(t_game *game, int direction);
void	rotate_player(t_game *game, double angle);

// Prototipos de funciones en parse_map.c
void	parse_map(t_game *game, const char *filename);
int		validate_map(t_game *game);
int		check_map_grid(t_game *game, int *player_x, int *player_y);
void	find_player(t_game *game, int i, int j);
int		is_valid_char(char c);
int		is_border(int i, int j, t_map *map);
void	parse_textures(t_game *game, char *line);
int		parse_color(char *str);

// Prototipos de funciones en render.c
void	render_frame(t_game *game);
// void	draw_line(t_img *img, int x, int start, int end, int color);

// Prototipos de funciones en textures.c
void	load_textures(t_game *game);
void	free_textures(t_game *game);

// Prototipos de funciones en cleanup.c
void	clean_split(char **split);
void	free_window(t_game *game);
void	exit_game(t_game *game, const char *msg);

#endif
