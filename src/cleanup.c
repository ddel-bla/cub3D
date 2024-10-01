#include "../include/cub3d.h"

// Función para liberar la memoria de las texturas
// void free_textures(t_game *game)
// {
//     if (game->textures)
//     {
//         for (int i = 0; i < 4; i++) // Asumiendo que tienes 4 texturas
//         {
//             if (game->textures[i])
//                 free(game->textures[i]);
//         }
//         free(game->textures);
//     }
// }

// Función para liberar la memoria del mapa
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

// Función para liberar la imagen y la ventana de MiniLibX
void free_window(t_game *game)
{
    if (game->window.img.img_ptr)
        mlx_destroy_image(game->window.mlx_ptr, game->window.img.img_ptr);
    if (game->window.win_ptr)
        mlx_destroy_window(game->window.mlx_ptr, game->window.win_ptr);
}

// Función principal para liberar todos los recursos y salir del juego
void exit_game(t_game *game, const char *msg)
{
    if (msg)
        printf("%s\n", msg); // Imprime el mensaje de error si existe

    // Llamar a las funciones de limpieza
    free_textures(game);
    free_map(game);
    free_window(game);

    // Si es necesario, también podrías liberar otras cosas aquí...

    // Salir del programa
    exit(msg ? EXIT_FAILURE : EXIT_SUCCESS);
}
