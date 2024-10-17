/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:59:06 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/12 14:23:27 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Función para liberar la memoria del mapa
void	free_map(t_game *g)
{
	int	i;

	i = 0;
	if (g->map.grid)
	{
		while (i < g->map.height)
		{
			if (g->map.grid[i])
				free(g->map.grid[i]);
			i++;
		}
		free(g->map.grid);
	}
}

// Función para liberar la imagen y la ventana de MiniLibX
void	free_window(t_game *g)
{
	if (g->win.img.img_ptr)
		mlx_destroy_image(g->win.mlx_p, g->win.img.img_ptr);
	if (g->win.win_p)
		mlx_destroy_window(g->win.mlx_p, g->win.win_p);
}

// Función principal para liberar todos los recursos y salir del juego
void	exit_game(t_game *g, const char *msg)
{
	free_textures(g);
	free_map(g);
	free_window(g);
	if (!msg)
		exit(EXIT_SUCCESS);
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}
void	free_textures(t_game *g)
{
	free(g->no);
	free(g->so);
	free(g->ea);
	free(g->we);
}

void	clean_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}