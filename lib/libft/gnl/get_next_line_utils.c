/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 13:07:34 by ddel-bla          #+#    #+#             */
/*   Updated: 2023/03/12 13:07:34 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char
	*ft_gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	
	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	x;
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	x = 0;
	while (s2[x])
		str[i++] = s2[x++];
	str[i] = 0;
	free(s1);
	return (str);
}

int
	ft_gnl_get_len(char *left_str)
{
	int		i;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (left_str[i] != '\n')
		i--;
	return (i);
}
