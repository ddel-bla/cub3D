/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:14:58 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/14 18:42:48 by ddel-bla         ###   ########.fr       */
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
	if (i.width != TEX_W || i.height != TEX_H)
		exit_game(g, "Error: Texture size mismatch.");
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

void	load_textures(t_game *g)
{
	int	i;

	if (g->textures)
		free_textures(g);
	g->textures = (int **)malloc(sizeof(int *) * 4);
	if (!g->textures)
		exit_game(g, "Error: Failed to allocate memory for textures.");
	i = 0;
	while (i < 4)
	{
		g->textures[i] = (int *)malloc(sizeof(int) * (TEX_W * TEX_H));
		if (!g->textures[i])
			exit_game(g, "Error: Failed to allocate memory for a texture.");
		i++;
	}
	fprintf(stderr, "Loading textures...\n");
	load_texture(g, g->textures[0], "assets/textures/floor.xpm");
	load_texture(g, g->textures[1], "assets/textures/floor.xpm");
	load_texture(g, g->textures[2], "assets/textures/floor.xpm");
	load_texture(g, g->textures[3], "assets/textures/floor.xpm");
	fprintf(stderr, "All textures loaded successfully.\n");
}

void	free_textures(t_game *g)
{
	int	i;

	if (!g->textures)
		return ;
	i = 0;
	while (i < 4)
	{
		if (g->textures[i])
		{
			free(g->textures[i]);
			g->textures[i] = NULL;
		}
		i++;
	}
	free(g->textures);
	g->textures = NULL;
}
