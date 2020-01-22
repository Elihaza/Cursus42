/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:29:15 by ellarbi           #+#    #+#             */
/*   Updated: 2020/01/14 15:29:20 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*next;

	if (!(list = *lst))
		return ;
	while (list)
	{
		next = list->next;
		del(list->content);
		free(list);
		list = next;
	}
	*lst = NULL;
}
