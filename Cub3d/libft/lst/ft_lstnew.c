/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:51:53 by frdescam          #+#    #+#             */
/*   Updated: 2020/05/26 18:48:34 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(const char *name, void *content)
{
	t_list	*new_elem;

	if (!(new_elem = malloc(sizeof(t_list))))
		return (NULL);
	new_elem->name = ft_strdup(name);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}
/*
**#include <stdio.h>
**
**int		main(void)
**{
**	char	str[] = "lorem ipsum dolor sit";
**	char	name[] = "this is my name";
**
**	t_list	*elem;
**
**	elem = ft_lstnew(name, (void *)str);
**	printf("\nname : %s\ncontent : %s\n", elem->name, (char *)elem->content);
**}
*/
