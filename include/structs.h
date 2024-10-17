/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:44:39 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/15 18:13:16 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdint.h>

// Estructura para representar la ventana y la imagen
typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		size_line;
	int		endian;
	int		width;
	int		height;
}	t_img;

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
typedef struct s_map
{
	int		width;
	int		height;
	char	**grid;
}	t_map;

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
	t_textures	texture_paths;
	int         control_flags;
}	t_game;
//---------
typedef struct s_ray
{
	double	ray_dir_x;        // Dirección del rayo en el eje X
	double	ray_dir_y;        // Dirección del rayo en el eje Y
	double	side_dist_x;      // Distancia actual que debe recorrer el rayo en X para cruzar el próximo borde de un bloque
	double	side_dist_y;      // Distancia actual que debe recorrer el rayo en Y para cruzar el próximo borde de un bloque
	double	perp_w_d;         // Distancia perpendicular desde el jugador hasta la pared impactada
	int		step_x;           // Dirección en la que avanzará el rayo en el eje X (puede ser -1 o 1)
	int		step_y;           // Dirección en la que avanzará el rayo en el eje Y (puede ser -1 o 1)
	int		map_x;            // Posición actual del rayo en el mapa en X (cuadrícula del mapa)
	int		map_y;            // Posición actual del rayo en el mapa en Y (cuadrícula del mapa)
	int		side;             // Indica si el rayo golpeó una pared vertical (0) o una horizontal (1)
}	t_ray;

typedef struct s_wall
{
	int	line_height;   // Altura de la pared que se debe dibujar
	int	draw_start;    // Inicio del dibujo de la pared en la pantalla
	int	draw_end;      // Fin del dibujo de la pared en la pantalla
}	t_wall;

typedef struct s_line
{
	int		x;
	int		start;
	int		end;
	int		color;
}	t_line;

#endif
