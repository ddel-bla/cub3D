/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 16:23:42 by claferna          #+#    #+#             */
/*   Updated: 2024/05/18 16:27:12 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace_char(const char *str, char find, char replace)
{
	size_t	len;
	size_t	i;
	char	*result;

	len = 0;
	while (str[len] != '\0')
		len++;
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	i = 0;
	while (i < len)
	{
		if (str[i] == find)
			result[i] = replace;
		else
			result[i] = str[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}
