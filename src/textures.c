#include "../include/cub3d.h"

void	load_textures(t_game *game)
{
	game->textures[0] = mlx_xpm_file_to_image(game->window.mlx_ptr,
				game->texture_paths.north_texture,
				&game->map.width, &game->map.height);
	if (!game->textures[0])
		exit_game(game, "Error: Failed to load north texture.");

	game->textures[1] = mlx_xpm_file_to_image(game->window.mlx_ptr,
				game->texture_paths.south_texture,
				&game->map.width, &game->map.height);
	if (!game->textures[1])
		exit_game(game, "Error: Failed to load south texture.");

	game->textures[2] = mlx_xpm_file_to_image(game->window.mlx_ptr,
				game->texture_paths.west_texture,
				&game->map.width, &game->map.height);
	if (!game->textures[2])
		exit_game(game, "Error: Failed to load west texture.");

	game->textures[3] = mlx_xpm_file_to_image(game->window.mlx_ptr,
				game->texture_paths.east_texture,
				&game->map.width, &game->map.height);
	if (!game->textures[3])
		exit_game(game, "Error: Failed to load east texture.");
}
int ft_isspace(int c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

int parse_color(char *str)
{
	int r;
	int g;
	int b;

	r = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str != ',')
		return (-1);
	str++;
	g = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	if (*str != ',')
		return (-1);
	str++;
	b = ft_atoi(str);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
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
	else if (ft_strncmp(line, "F ", 2) == 0)
		game->texture_paths.floor_color = parse_color(line + 2);
	else if (ft_strncmp(line, "C ", 2) == 0)
    {
		game->texture_paths.ceiling_color = parse_color(line + 2);
        game->control_flags = 1;
    }
	else
		exit_game(game, "Error: Invalid identifier in .cub file.");
}
