#include "../include/cub3d.h"

int render_wrapper(void *param)
{
    t_game *game;

    game = (t_game *)param; // Convertir el parámetro a t_game *
    render_frame(game);     // Llamar a la función render_frame
    return (0);             // Retornar 0, ya que mlx_loop_hook espera un int
}

int	main(int argc, char **argv)
{
    t_game game;

    // Verificar el número de argumentos
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <map_file.cub>\n", argv[0]);
        return (EXIT_FAILURE);
    }
    init_game(&game);
    parse_map(&game, argv[1]);
    init_window(&game);
    load_textures(&game);

    // Registrar los eventos
    mlx_hook(game.window.win_ptr, 2, 1L<<0, handle_keypress, &game); // Key press
    mlx_hook(game.window.win_ptr, 3, 1L<<1, handle_keyrelease, &game); // Key release
    mlx_hook(game.window.win_ptr, 17, 1L<<17, close_window, &game); // Close window

    // Iniciar el bucle principal del juego
    mlx_loop_hook(game.window.mlx_ptr, render_wrapper, &game);
    mlx_loop(game.window.mlx_ptr);

    // Salir del juego y limpiar recursos
    exit_game(&game, NULL);

    return (EXIT_SUCCESS);
}
