/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:14:58 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/12 14:18:02 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	load_texture(t_game *g, int *texture, char *path)
{
	t_img	i;
	int		x;
	int		y;

	i.img_ptr = mlx_xpm_file_to_image(g->win.mlx_p, path, &i.width, &i.height);
	if (!i.img_ptr)
		exit_game(g, "Error: Failed to load texture.");
	i.data = (int *)mlx_get_data_addr(i.img_ptr, &i.bpp, &i.size_line,
			&i.endian);
	if (!i.data)
		exit_game(g, "Error: Failed to get texture data address.");
	y = 0;
	while (y < TEX_H)
	{
		x = 0;
		while (x < TEX_W)
		{
			texture[TEX_W * y + x] = i.data[TEX_W * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(g->win.mlx_p, i.img_ptr);
}

// Función para cargar todas las texturas necesarias
void	load_textures(t_game *g)
{
	int	i;

	i = 0;
	g->textures = (int **)malloc(sizeof(int *) * 2);
	if (!g->textures)
		exit_game(g, "Error: Failed to allocate memory for textures.");
	while (i < 2)
	{
		g->textures[i] = (int *)malloc(sizeof(int) * (TEX_W * TEX_H));
		if (!g->textures[i])
			exit_game(g, "Error: Failed to allocate memory for a texture.");
		i++;
	}
	load_texture(g, g->textures[0], "assets/textures/wall.xpm");
	load_texture(g, g->textures[1], "assets/textures/floor.xpm");
}

// Función para liberar la memoria de las texturas
void	free_textures(t_game *g)
{
	int	i;

	i = 0;
	while (i < 2 && g->textures)
	{
		if (g->textures[i])
		{
			free(g->textures[i]);
			g->textures[i] = NULL;
		}
		i++;
	}
	free(g->textures);
}
