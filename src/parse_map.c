#include "../include/cub3d.h"

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
    if (!content)
        return (NULL);

    line = get_next_line(fd);
    while (line)
    {
        temp = ft_strjoin(content, line);
        free(content);
        content = temp;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (content);
}

/* static int validate_map(t_map *map)
{
    int i;
    int j;
 
    i = 0;
    j = 0;
    while (i < map->height)
    {
        while (j < map->width)
        {
            if (map->grid[i][j] != '1' && map->grid[i][j] != '0')
                return (0);
            if ((i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1) &&
                map->grid[i][j] != '1')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
} */
void    clean_split(char **split)
{
    int i;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}
// Función para cargar el contenido en la estructura del mapa
static void load_map(t_game *game, char *content)
{
    char    **lines;
    int     i;

    i = 0;
    lines = ft_split(content, '\n');
    game->map.height = 0;
    while (lines[game->map.height])
        game->map.height++;

    game->map.grid = (char **)malloc(sizeof(char *) * (game->map.height + 1));
    if (!game->map.grid)
        exit_game(game, "Error: Unable to allocate memory for map grid.");    
    while (i < game->map.height)
    {
        game->map.grid[i] = ft_strdup(lines[i]);
        if (!game->map.grid[i])
            exit_game(game, "Error: Unable to allocate memory for map row.");
        i++;
    }
    game->map.grid[game->map.height] = NULL;
    clean_split(lines);
  /*   if (!validate_map(&game->map))
        exit_game(game, "Error: Invalid map."); */
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

