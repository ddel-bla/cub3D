#include "../include/cub3d.h"

// Función para mover al jugador hacia adelante o hacia atrás
void move_player(t_game *game, int direction)
{
    double new_pos_x;
    double new_pos_y;

    new_pos_x = game->pla.pos_x + direction * game->pla.move_speed * game->pla.dir_x;
    new_pos_y = game->pla.pos_y + direction * game->pla.move_speed * game->pla.dir_y;

    // Verificar colisiones con el mapa antes de mover al jugador
    if (game->map.grid[(int)new_pos_y][(int)game->pla.pos_x] != '1')
        game->pla.pos_y = new_pos_y;
    if (game->map.grid[(int)game->pla.pos_y][(int)new_pos_x] != '1')
        game->pla.pos_x = new_pos_x;
}

// Función para mover al jugador hacia los lados (izquierda o derecha)
void strafe_player(t_game *game, int direction)
{
    double new_pos_x;
    double new_pos_y;

    new_pos_x = game->pla.pos_x + direction * game->pla.move_speed * game->pla.plane_x;
    new_pos_y = game->pla.pos_y + direction * game->pla.move_speed * game->pla.plane_y;

    // Verificar colisiones con el mapa antes de mover al jugador
    if (game->map.grid[(int)new_pos_y][(int)game->pla.pos_x] != '1')
        game->pla.pos_y = new_pos_y;
    if (game->map.grid[(int)game->pla.pos_y][(int)new_pos_x] != '1')
        game->pla.pos_x = new_pos_x;
}

// Función para rotar al jugador
void rotate_player(t_game *game, double angle)
{
    double old_dir_x;
    double old_plane_x;

    old_dir_x = game->pla.dir_x;
    game->pla.dir_x = game->pla.dir_x * cos(angle) - game->pla.dir_y * sin(angle);
    game->pla.dir_y = old_dir_x * sin(angle) + game->pla.dir_y * cos(angle);

    old_plane_x = game->pla.plane_x;
    game->pla.plane_x = game->pla.plane_x * cos(angle) - game->pla.plane_y * sin(angle);
    game->pla.plane_y = old_plane_x * sin(angle) + game->pla.plane_y * cos(angle);
}
