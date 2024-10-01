#include "../include/cub3d.h"

// Función para mover al jugador hacia adelante o hacia atrás
void move_player(t_game *game, int direction)
{
    double new_pos_x;
    double new_pos_y;

    new_pos_x = game->player.pos_x + direction * game->player.move_speed * game->player.dir_x;
    new_pos_y = game->player.pos_y + direction * game->player.move_speed * game->player.dir_y;

    // Verificar colisiones con el mapa antes de mover al jugador
    if (game->map.grid[(int)new_pos_y][(int)game->player.pos_x] != '1')
        game->player.pos_y = new_pos_y;
    if (game->map.grid[(int)game->player.pos_y][(int)new_pos_x] != '1')
        game->player.pos_x = new_pos_x;
}

// Función para mover al jugador hacia los lados (izquierda o derecha)
void strafe_player(t_game *game, int direction)
{
    double new_pos_x;
    double new_pos_y;

    new_pos_x = game->player.pos_x + direction * game->player.move_speed * game->player.plane_x;
    new_pos_y = game->player.pos_y + direction * game->player.move_speed * game->player.plane_y;

    // Verificar colisiones con el mapa antes de mover al jugador
    if (game->map.grid[(int)new_pos_y][(int)game->player.pos_x] != '1')
        game->player.pos_y = new_pos_y;
    if (game->map.grid[(int)game->player.pos_y][(int)new_pos_x] != '1')
        game->player.pos_x = new_pos_x;
}

// Función para rotar al jugador
void rotate_player(t_game *game, double angle)
{
    double old_dir_x;
    double old_plane_x;

    old_dir_x = game->player.dir_x;
    game->player.dir_x = game->player.dir_x * cos(angle) - game->player.dir_y * sin(angle);
    game->player.dir_y = old_dir_x * sin(angle) + game->player.dir_y * cos(angle);

    old_plane_x = game->player.plane_x;
    game->player.plane_x = game->player.plane_x * cos(angle) - game->player.plane_y * sin(angle);
    game->player.plane_y = old_plane_x * sin(angle) + game->player.plane_y * cos(angle);
}
