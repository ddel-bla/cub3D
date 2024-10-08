/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:44:39 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/08 14:48:48 by ddel-bla         ###   ########.fr       */
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

typedef struct s_window
{
	void	*mlx_p;
	void	*win_p;
	t_img	img;
}	t_window;

// Estructura para representar al jugador
typedef struct s_player
{
	double	pos_x;// Posición X
	double	pos_y;// Posición Y
	double	dir_x;// Dirección en el eje X
	double	dir_y;// Dirección en el eje Y
	double	plane_x;// Plano de la cámara en el eje X
	double	plane_y;// Plano de la cámara en el eje Y
	double	move_speed;
	double	rot_speed;
}	t_player;

// Estructura para el manejo del mapa
typedef struct s_map
{
	int		width;
	int		height;
	char	**grid;
}	t_map;

// Estructura principal del juego
typedef struct s_game
{
	t_window	win;
	t_player	pla;
	t_map		map;
	int			**textures;
}	t_game;

#endif
