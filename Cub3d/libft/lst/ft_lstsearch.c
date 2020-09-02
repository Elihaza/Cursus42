/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:40:41 by ellarbi           #+#    #+#             */
/*   Updated: 2020/07/25 13:39:01 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstsearch(t_list *lst, const char *name)
{
	while (lst)
	{
		if (ft_strcmp(name, lst->name) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
