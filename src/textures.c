/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r < cfeliz-r@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:14:58 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/21 10:49:52 by cfeliz-r         ###   ########.fr       */
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
	load_texture(g, g->no, g->texture_paths.north_texture);
	load_texture(g, g->so, g->texture_paths.south_texture);
	load_texture(g, g->ea, g->texture_paths.east_texture);
	load_texture(g, g->we, g->texture_paths.west_texture);
	fprintf(stderr, "All textures loaded successfully.\n");
}

int	parse_color(char *str)
{
	int	r;
	int	g;
	int	b;

	if (!ft_isdigit(*str))
		return (-1);
	r = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str++ != ',' || !ft_isdigit(*str))
		return (-1);
	g = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str++ != ',' || !ft_isdigit(*str))
		return (-1);
	b = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0' || r < 0 || r > 255
		|| g < 0 || g > 255 || b < 0 || b > 255)
		return (-1);
	return (r << 16 | g << 8 | b);
}

void	parse_textures(t_game *game, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		game->texture_paths.north_texture = ft_strdup(line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		game->texture_paths.south_texture = ft_strdup(line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		game->texture_paths.west_texture = ft_strdup(line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		game->texture_paths.east_texture = ft_strdup(line + 3);
	else if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
	{
		if (ft_strncmp(line, "F ", 2) == 0)
			game->floor = parse_color(line + 2);
		else
			game->ceiling = parse_color(line + 2);
		game->control_flags++;
	}
	else
		exit_game(game, "Error: Invalid identifier in .cub file.");
}
