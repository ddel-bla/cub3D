#ifndef CUB3D_H
#define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "structs.h"
#include "keys.h"
#include "../lib/minilibx/mlx.h"
#include "../lib/libft/libft.h"

// Definiciones de macros
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define TEX_WIDTH 64
#define TEX_HEIGHT 64

// Prototipos de funciones en init.c
void    init_game(t_game *game);
void    init_window(t_game *game);

// Prototipos de funciones en events.c
int     handle_keypress(int keycode, t_game *game);
int     handle_keyrelease(int keycode, t_game *game);
int     close_window(t_game *game);

// Prototipos de funciones en movement.c
void    move_player(t_game *game, int direction);
void    strafe_player(t_game *game, int direction);
void    rotate_player(t_game *game, double angle);

// Prototipos de funciones en parse_map.c
void    parse_map(t_game *game, const char *filename);

// Prototipos de funciones en render.c
void    render_frame(t_game *game);
void    draw_line(t_img *img, int x, int start, int end, int color);

// Prototipos de funciones en textures.c
void    load_textures(t_game *game);
void    free_textures(t_game *game);

// Prototipos de funciones en cleanup.c
void    free_map(t_game *game);
void    free_window(t_game *game);
void    exit_game(t_game *game, const char *msg);

#endif
