#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdint.h>

// Estructura para representar la ventana y la imagen
typedef struct s_img {
    void    *img_ptr;
    int     *data;
    int     bpp;
    int     size_line;
    int     endian;
    int     width;
    int     height;
}   t_img;

typedef struct s_window {
    void    *mlx_ptr;
    void    *win_ptr;
    t_img   img;
}   t_window;

// Estructura para representar al jugador
typedef struct s_player {
    double  pos_x;  // Posición X
    double  pos_y;  // Posición Y
    double  dir_x;  // Dirección en el eje X
    double  dir_y;  // Dirección en el eje Y
    double  plane_x; // Plano de la cámara en el eje X
    double  plane_y; // Plano de la cámara en el eje Y
    double  move_speed;
    double  rot_speed;
}   t_player;

// Estructura para el manejo del mapa
typedef struct s_map {
    int     width;
    int     height;
    char    **grid; // Representación del mapa en una matriz de chars
}   t_map;

// Estructura principal del juego
typedef struct s_game {
    t_window    window;
    t_player    player;
    t_map       map;
    int         **textures; // Array bidimensional para almacenar las texturas
}   t_game;

#endif
