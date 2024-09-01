/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:07:41 by ddel-bla          #+#    #+#             */
/*   Updated: 2023/03/12 13:07:41 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char
	*ft_read_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_gnl_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(left_str);
			return (NULL);
		}
		buff[rd_bytes] = 0;
		left_str = ft_gnl_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char
	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	i = ft_gnl_get_len(left_str);
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = 0;
	if (!left_str)
		return (free(left_str), NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
		return (free(left_str), NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = 0;
	return (free(left_str), str);
}

char
	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	left_str = ft_read_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>


int main(void)
{
	int	fd = open("read_error.txt", O_RDONLY);
	char str[] = "hola\n";
	char *line = str;

	while ((line = get_next_line(fd)))
	{
		//write(1, line, ft_strlen(line));
		printf("%s", line);
		free(line);
	}
	//system ("leaks a.out");
	close(fd);
	return (0);
}
*/