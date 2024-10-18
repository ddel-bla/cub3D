/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:44:39 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/18 15:54:01 by cfeliz-r         ###   ########.fr       */
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
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	move_speed;
	double	rot_speed;
	int		flag_player;
}	t_player;

typedef struct s_map
{
	int		width;
	int		height;
	char	**grid;
}	t_map;

typedef struct s_textures
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
}	t_textures;

typedef struct s_game
{
	t_window	win;
	t_player	pla;
	t_map		map;
	int			floor;
	int			ceiling;
	int			*no;
	int			*so;
	int			*ea;
	int			*we;
	t_textures	texture_paths;
	int			control_flags;
}	t_game;

typedef struct s_ray
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_w_d;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		side;
}	t_ray;

typedef struct s_wall
{
	int	line_height;
	int	draw_start;
	int	draw_end;
}	t_wall;

#endif
