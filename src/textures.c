/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:14:58 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/08 14:54:30 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	load_texture(t_game *g, int *texture, char *path)
{
	t_img img;
	int x, y;

	img.img_ptr = mlx_xpm_file_to_image(g->win.mlx_p, path, &img.width, &img.height);
	if (!img.img_ptr)
		exit_game(game, "Error: Failed to load texture.");

	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);
	if (!img.data)
		exit_game(game, "Error: Failed to get texture data address.");

	y = 0;
	while (y < TEX_HEIGHT)
	{
		x = 0;
		while (x < TEX_WIDTH)
		{
			texture[TEX_WIDTH * y + x] = img.data[TEX_WIDTH * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(g->win.mlx_p, img.img_ptr);
}

// Función para cargar todas las texturas necesarias
void	load_textures(t_game *g)
{
	int i;

	i = 0;
	g->textures = (int **)malloc(sizeof(int *) * 2);
	if (!g->textures)
		exit_game(game, "Error: Failed to allocate memory for textures.");
	while (i < 2)
	{
		g->textures[i] = (int *)malloc(sizeof(int) * (TEX_WIDTH * TEX_HEIGHT));
		if (!g->textures[i])
			exit_game(game, "Error: Failed to allocate memory for a texture.");
		i++;
	}
	load_texture(game, g->textures[0], "assets/textures/wall.xpm");
	load_texture(game, g->textures[1], "assets/textures/floor.xpm");
}

// Función para liberar la memoria de las texturas
void	free_textures(t_game *g)
{
	int i;

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
