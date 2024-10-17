/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:20:23 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/17 00:01:52 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Función para mover al jugador hacia adelante o hacia atrás
void	move_player(t_game *g, int dir)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = g->pla.pos_x + dir * g->pla.move_speed * g->pla.dir_x;
	new_pos_y = g->pla.pos_y + dir * g->pla.move_speed * g->pla.dir_y;
	if (g->map.grid[(int)new_pos_y][(int)g->pla.pos_x] != '1')
		g->pla.pos_y = new_pos_y;
	if (g->map.grid[(int)g->pla.pos_y][(int)new_pos_x] != '1')
		g->pla.pos_x = new_pos_x;
}

// Función para mover al jugador hacia los lados (izquierda o derecha)
void	strafe_player(t_game *g, int dir)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = g->pla.pos_x + dir * g->pla.move_speed * g->pla.plane_x;
	new_pos_y = g->pla.pos_y + dir * g->pla.move_speed * g->pla.plane_y;
	if (g->map.grid[(int)new_pos_y][(int)g->pla.pos_x] != '1')
		g->pla.pos_y = new_pos_y;
	if (g->map.grid[(int)g->pla.pos_y][(int)new_pos_x] != '1')
		g->pla.pos_x = new_pos_x;
}

// Función para rotar al jugador
void	rotate_player(t_game *g, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = g->pla.dir_x;
	g->pla.dir_x = g->pla.dir_x * cos(angle) - g->pla.dir_y * sin(angle);
	g->pla.dir_y = old_dir_x * sin(angle) + g->pla.dir_y * cos(angle);
	old_plane_x = g->pla.plane_x;
	g->pla.plane_x = g->pla.plane_x * cos(angle) - g->pla.plane_y * sin(angle);
	g->pla.plane_y = old_plane_x * sin(angle) + g->pla.plane_y * cos(angle);
}
