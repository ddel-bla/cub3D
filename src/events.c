/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:29:15 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/12 09:31:06 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Manejo de la presión de teclas
int	handle_keypress(int keycode, t_game *g)
{
	if (keycode == KEY_W)
		move_player(g, 1);
	if (keycode == KEY_S)
		move_player(g, -1);
	if (keycode == KEY_A)
		strafe_player(g, -1);
	if (keycode == KEY_D)
		strafe_player(g, 1);
	if (keycode == KEY_LEFT)
		rotate_player(g, -g->pla.rot_speed);
	if (keycode == KEY_RIGHT)
		rotate_player(g, g->pla.rot_speed);
	if (keycode == KEY_ESC)
		exit_game(g, NULL);
	return (0);
}

// Manejo del cierre de la ventana
int	close_window(t_game *g)
{
	exit_game(g, NULL);
	return (0);
}
