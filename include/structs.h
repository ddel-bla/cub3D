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
    void    *mlx_p;
    void    *win_p;
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
    int     flag_player;
}   t_player;

// Estructura para el manejo del mapa
typedef struct s_map {
    int     width;
    int     height;
    char    **grid; // Representación del mapa en una matriz de chars
}   t_map;

typedef struct s_textures
{
    char    *north_texture;
    char    *south_texture;
    char    *west_texture;
    char    *east_texture;
}   t_textures;


// Estructura principal del juego
typedef struct s_game {
    t_window    win;
    t_player    pla;
    t_map       map;
    int			floor;
	int			ceiling;
	int			*no;
	int			*so;
	int			*ea;
	int			*we;
    t_textures  texture_paths;
    int         control_flags;
}   t_game;

#endif
