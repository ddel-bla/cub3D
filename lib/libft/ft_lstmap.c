/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:49:10 by claferna          #+#    #+#             */
/*   Updated: 2024/03/18 17:55:57 by claferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** LIBRARY: N/A
**
** DESCRIPTION: Iteraates through the list 'lst' and applies the function 'f'
** to the content of each node. It creates a list of the correct and 
** successive application of the function 'f' over each node. The 'del'
** function is used to delete the contents of a node, if you do lack.
*/

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_lst;
	t_list	*new_elem;

	if (!lst || !f || !del)
		return (0);
	result_lst = 0;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			ft_lstclear(&result_lst, del);
			return (0);
		}
		ft_lstadd_back(&result_lst, new_elem);
		lst = lst->next;
	}
	return (result_lst);
}
