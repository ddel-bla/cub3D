#include "cub3d.h"

// Función auxiliar para leer el contenido del archivo en una cadena
static char *read_file(const char *filename)
{
    int     fd;
    char    *line;
    char    *content;
    char    *temp;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);

    content = ft_strdup("");
    while (get_next_line(fd, &line) > 0)
    {
        temp = ft_strjoin(content, line);
        free(content);
        content = ft_strjoin(temp, "\n");
        free(temp);
        free(line);
    }
    close(fd);
    return (content);
}

// Función para validar el contenido del mapa
static int validate_map(t_map *map)
{
    int i, j;

    // Validar que el mapa esté completamente rodeado de paredes (celdas '1')
    for (i = 0; i < map->height; i++)
    {
        for (j = 0; j < map->width; j++)
        {
            if (map->grid[i][j] != '1' && map->grid[i][j] != '0')
                return (0); // Solo se permiten '1' y '0' (o añadir más según las necesidades)
            if ((i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1) &&
                map->grid[i][j] != '1')
                return (0); // Asegurar que los bordes son '1'
        }
    }
    return (1);
}

// Función para cargar el contenido en la estructura del mapa
static void load_map(t_game *game, char *content)
{
    char    **lines;
    int     i;

    lines = ft_split(content, '\n');
    game->map.height = 0;
    while (lines[game->map.height])
        game->map.height++;

    game->map.grid = (char **)malloc(sizeof(char *) * (game->map.height + 1));
    if (!game->map.grid)
        exit_game(game, "Error: Unable to allocate memory for map grid.");

    for (i = 0; i < game->map.height; i++)
    {
        game->map.grid[i] = ft_strdup(lines[i]);
        if (!game->map.grid[i])
            exit_game(game, "Error: Unable to allocate memory for map row.");
    }
    game->map.grid[game->map.height] = NULL;
    free(lines);

    if (!validate_map(&game->map))
        exit_game(game, "Error: Invalid map.");
}

// Función principal para parsear el archivo del mapa
void parse_map(t_game *game, const char *filename)
{
    char *content;

    content = read_file(filename);
    if (!content)
        exit_game(game, "Error: Unable to read map file.");

    load_map(game, content);
    free(content);
}

