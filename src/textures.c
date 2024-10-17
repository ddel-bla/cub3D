/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:14:58 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/17 12:06:37 by ddel-bla         ###   ########.fr       */
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

int	*select_texture(t_game *g, t_ray *r)
{
	if (r->side == 0 && r->ray_dir_x > 0)
		return (g->ea);
	else if (r->side == 0 && r->ray_dir_x < 0)
		return (g->we);
	else if (r->side == 1 && r->ray_dir_y > 0)
		return (g->so);
	return (g->no);
}

void	load_textures(t_game *g)
{
	fprintf(stderr, "Loading textures...\n");
	load_texture(g, g->no, "textures/wolfenstein/grey_stone.xpm");
	load_texture(g, g->so, "textures/wolfenstein/grey_stone.xpm");
	load_texture(g, g->ea, "textures/wolfenstein/grey_stone.xpm");
	load_texture(g, g->we, "textures/wolfenstein/grey_stone.xpm");
	fprintf(stderr, "All textures loaded successfully.\n");
}

void	free_textures(t_game *g)
{
	free(g->no);
	free(g->so);
	free(g->ea);
	free(g->we);
}
