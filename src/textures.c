#include "../include/cub3d.h"

// Función para cargar una única textura desde un archivo XPM
static void load_texture(t_game *game, int *texture, char *path)
{
    t_img img;
    int x, y;

    img.img_ptr = mlx_xpm_file_to_image(game->window.mlx_ptr, path, &img.width, &img.height);
    if (!img.img_ptr)
        exit_game(game, "Error: Failed to load texture.");

    img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_line, &img.endian);

    for (y = 0; y < TEX_HEIGHT; y++)
    {
        for (x = 0; x < TEX_WIDTH; x++)
        {
            texture[TEX_WIDTH * y + x] = img.data[TEX_WIDTH * y + x];
        }
    }
    mlx_destroy_image(game->window.mlx_ptr, img.img_ptr);
}

// Función para cargar todas las texturas necesarias
void load_textures(t_game *game)
{
    game->textures = (int **)malloc(sizeof(int *) * 4); // Asumimos 4 texturas para 4 tipos de paredes
    if (!game->textures)
        exit_game(game, "Error: Failed to allocate memory for textures.");

    for (int i = 0; i < 4; i++)
    {
        game->textures[i] = (int *)malloc(sizeof(int) * (TEX_WIDTH * TEX_HEIGHT));
        if (!game->textures[i])
            exit_game(game, "Error: Failed to allocate memory for a texture.");
    }

    // Cargar texturas desde archivos XPM
    load_texture(game, game->textures[0], "assets/textures/wall1.xpm");
    load_texture(game, game->textures[1], "assets/textures/wall2.xpm");
    load_texture(game, game->textures[2], "assets/textures/wall3.xpm");
    load_texture(game, game->textures[3], "assets/textures/wall4.xpm");
}

// Función para liberar la memoria de las texturas
void free_textures(t_game *game)
{
    for (int i = 0; i < 4; i++)
    {
        if (game->textures[i])
            free(game->textures[i]);
    }
    free(game->textures);
}
