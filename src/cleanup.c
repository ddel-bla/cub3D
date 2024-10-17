#include "../include/cub3d.h"

void free_map(t_game *game)
{
    if (game->map.grid)
    {
        for (int i = 0; i < game->map.height; i++)
        {
            if (game->map.grid[i])
                free(game->map.grid[i]);
        }
        free(game->map.grid);
    }
}

void free_window(t_game *game)
{
    if (game->win.img.img_ptr)
        mlx_destroy_image(game->win.mlx_p, game->win.img.img_ptr);
    if (game->win.win_p)
        mlx_destroy_window(game->win.mlx_p, game->win.win_p);
}

void	free_textures(t_game *g)
{
	free(g->no);
	free(g->so);
	free(g->ea);
	free(g->we);
}

void exit_game(t_game *game, const char *msg)
{
    if (msg)
        printf("%s\n", msg);
    free_textures(game);
    free_map(game);
    free_window(game);
    if (msg)
        exit(EXIT_FAILURE);
    else
        exit(EXIT_SUCCESS);
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