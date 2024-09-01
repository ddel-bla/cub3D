#include "cub3d.h"

// Manejo de la presión de teclas
int handle_keypress(int keycode, t_game *game)
{
    if (keycode == KEY_W) // Mover hacia adelante
        move_player(game, 1);
    if (keycode == KEY_S) // Mover hacia atrás
        move_player(game, -1);
    if (keycode == KEY_A) // Mover hacia la izquierda
        strafe_player(game, -1);
    if (keycode == KEY_D) // Mover hacia la derecha
        strafe_player(game, 1);
    if (keycode == KEY_LEFT) // Rotar hacia la izquierda
        rotate_player(game, -game->player.rot_speed);
    if (keycode == KEY_RIGHT) // Rotar hacia la derecha
        rotate_player(game, game->player.rot_speed);
    if (keycode == KEY_ESC) // Salir del juego
        exit_game(game, NULL);
    return (0);
}

// Manejo del levantamiento de teclas
int handle_keyrelease(int keycode, t_game *game)
{
    // Esta función puede quedar vacía si no necesitas manejar eventos al soltar las teclas.
    (void)keycode;
    (void)game;
    return (0);
}

// Manejo del cierre de la ventana
int close_window(t_game *game)
{
    exit_game(game, NULL);
    return (0);
}
