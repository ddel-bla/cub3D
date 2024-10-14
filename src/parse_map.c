/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 09:32:46 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/10/14 14:22:52 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

// Función auxiliar para leer el contenido del archivo en una cadena
static char	*read_file(const char *filename)
{
	int		fd;
	char	*line;
	char	*content;
	char	*temp;

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

static void	clean_split(char **split)
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

// Función para cargar el contenido en la estructura del mapa
static void	load_map(t_game *g, char *content)
{
	char	**lines;
	int		i;

	i = 0;
	lines = ft_split(content, '\n');
	g->map.height = 0;
	while (lines[g->map.height])
		g->map.height++;
	g->map.width = ft_strlen(lines[0]);
	g->map.grid = (char **)malloc(sizeof(char *) * (g->map.height + 1));
	if (!g->map.grid)
		exit_game(g, "Error: Unable to allocate memory for map grid.");
	while (i < g->map.height)
	{
		g->map.grid[i] = ft_strdup(lines[i]);
		if (!g->map.grid[i])
			exit_game(g, "Error: Unable to allocate memory for map row.");
		fprintf(stderr, "Loaded map row %d: %s\n", i, g->map.grid[i]);  // Depuración para verificar
		i++;
	}
	g->map.grid[g->map.height] = NULL;
	clean_split(lines);
}

// Función principal para parsear el archivo del mapa
void	parse_map(t_game *g, const char *filename)
{
	char	*content;

	content = read_file(filename);
	if (!content)
		exit_game(g, "Error: Unable to read map file.");
	load_map(g, content);
	fprintf(stderr, "Map width: %d, Map height: %d\n", g->map.width, g->map.height);
	free(content);
}
