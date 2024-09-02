#include <cub3d.h>

// Función para inicializar la estructura del juego
void init_game(t_game *game)
{
    // Inicialización de la ventana y la imagen
    game->window.mlx_ptr = NULL;
    game->window.win_ptr = NULL;
    game->window.img.img_ptr = NULL;
    game->window.img.data = NULL;
    game->player.pos_x = 0;
    game->player.pos_y = 0;
    game->player.dir_x = -1;
    game->player.dir_y = 0;
    game->player.plane_x = 0;
    game->player.plane_y = 0.66;
    game->player.move_speed = 0.05;
    game->player.rot_speed = 0.03;
    game->map.grid = NULL;
    game->textures = NULL;
}

// Función para inicializar la ventana y la imagen
void init_window(t_game *game)
{
    game->window.mlx_ptr = mlx_init();
    if (!game->window.mlx_ptr)
        exit_game(game, "Error: Unable to initialize MLX.");

    game->window.win_ptr = mlx_new_window(game->window.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
    if (!game->window.win_ptr)
        exit_game(game, "Error: Unable to create window.");

    game->window.img.img_ptr = mlx_new_image(game->window.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    if (!game->window.img.img_ptr)
        exit_game(game, "Error: Unable to create image.");

    game->window.img.data = (int *)mlx_get_data_addr(game->window.img.img_ptr,
                                                     &game->window.img.bpp,
                                                     &game->window.img.size_line,
                                                     &game->window.img.endian);
    if (!game->window.img.data)
        exit_game(game, "Error: Unable to get image data address.");
}

// Función para cargar texturas (esqueleto básico)
void load_textures(t_game *game)
{
    // Suponiendo que tengas un array de texturas precargadas
    // Esto es solo un esqueleto básico. Deberías reemplazarlo
    // con la lógica de carga de texturas real de tu juego.
    game->textures = malloc(sizeof(int *) * 4); // Por ejemplo, para 4 texturas
    if (!game->textures)
        exit_game(game, "Error: Unable to allocate memory for textures.");

    // Aquí deberías cargar cada textura en la memoria
    // Por ejemplo:
    game->textures[0] = (int *)mlx_xpm_file_to_image(game->window.mlx_ptr, "assets/textures/wall.xpm",
                                                     &game->window.img.width, &game->window.img.height);
    if (!game->textures[0])
        exit_game(game, "Error: Unable to load texture 0.");
    // Repite para otras texturas...
}

