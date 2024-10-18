/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfeliz-r <cfeliz-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:53:41 by claferna          #+#    #+#             */
/*   Updated: 2024/10/18 15:43:14 by cfeliz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: <stdlib.h>
**
** DESCRIPTION: Converts the initial portion of the string pointed to by
** str to int representation
*/

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	result;
	int	i;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		str++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}
/*
#include <stdio.h>
int main(void)
{
	printf("%d", ft_atoi("  \n+123asd"));

}*/

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\r');
}
