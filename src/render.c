/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:21:04 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/08 14:54:19 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Función para dibujar una línea vertical en la imagen
void draw_line(t_img *img, int x, int start, int end, int color)
{
	int y;

	if (start < 0)
		start = 0;
	if (end >= WIN_H)
		end = WIN_H - 1;
	y = start;
	while (y <= end)
	{
		img->data[y * WIN_W + x] = color;
		y++;
	}
}

// Función principal de renderizado con raycasting
void render_frame(t_game *g)
{
	int x;

	x = 0;
	while (x < WIN_W)
	{
		// Calcular posición y dirección del rayo
		double camera_x = 2 * x / (double)WIN_W - 1; // Rango: [-1, 1]
		double ray_dir_x = g->pla.dir_x + g->pla.plane_x * camera_x;
		double ray_dir_y = g->pla.dir_y + g->pla.plane_y * camera_x;

		// Posición del jugador en la cuadrícula
		int map_x = (int)g->pla.pos_x;
		int map_y = (int)g->pla.pos_y;

		// Longitud de los lados del rayo desde el punto de inicio hasta el siguiente eje
		double side_dist_x;
		double side_dist_y;

		// Longitud del rayo desde un lado del cuadrado al siguiente en la cuadrícula
		double delta_dist_x = fabs(1 / ray_dir_x);
		double delta_dist_y = fabs(1 / ray_dir_y);
		double perp_wall_dist;

		// Dirección de movimiento en la cuadrícula y verificación de pasos
		int step_x;
		int step_y;

		int hit = 0; // ¿Ha golpeado una pared?
		int side; // ¿Fue una pared vertical u horizontal?

		// Calcular la dirección y la distancia inicial de los rayos
		if (ray_dir_x < 0)
		{
			step_x = -1;
			side_dist_x = (g->pla.pos_x - map_x) * delta_dist_x;
		}
		else
		{
			step_x = 1;
			side_dist_x = (map_x + 1.0 - g->pla.pos_x) * delta_dist_x;
		}
		if (ray_dir_y < 0)
		{
			step_y = -1;
			side_dist_y = (g->pla.pos_y - map_y) * delta_dist_y;
		}
		else
		{
			step_y = 1;
			side_dist_y = (map_y + 1.0 - g->pla.pos_y) * delta_dist_y;
		}

		// DDA (Digital Differential Analysis) para detectar colisiones con paredes
		while (hit == 0)
		{
			if (side_dist_x < side_dist_y)
			{
				side_dist_x += delta_dist_x;
				map_x += step_x;
				side = 0;
			}
			else
			{
				side_dist_y += delta_dist_y;
				map_y += step_y;
				side = 1;
			}
			/* if (g->map.grid[map_y][map_x] == '1') // Si golpea una pared
				hit = 1; */
		}

		// Calcular la distancia perpendicular desde el jugador a la pared
		if (side == 0)
			perp_wall_dist = (map_x - g->pla.pos_x + (1 - step_x) / 2) / ray_dir_x;
		else
			perp_wall_dist = (map_y - g->pla.pos_y + (1 - step_y) / 2) / ray_dir_y;

		// Calcular la altura de la línea para dibujar la pared
		int line_height = (int)(WIN_H / perp_wall_dist);

		// Calcular el inicio y el final de la línea en la pantalla
		int draw_start = -line_height / 2 + WIN_H / 2;
		int draw_end = line_height / 2 + WIN_H / 2;

		// Elegir un color para la pared (puedes variar esto o cargar texturas)
		int color;
		if (side == 0)
			color = 0xFF0000; // Rojo para las paredes verticales
		else
			color = 0x00FF00; // Verde para las paredes horizontales

		// Dibujar la línea para este rayo
		draw_line(&g->window.img, x, draw_start, draw_end, color);

		x++;
	}

	// Actualizar la ventana con la imagen renderizada
	mlx_put_image_to_window(g->win.mlx_p, g->win.win_p, g->win.img.img_ptr, 0, 0);
}
