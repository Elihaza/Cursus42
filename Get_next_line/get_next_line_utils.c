/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:19:35 by ellarbi           #+#    #+#             */
/*   Updated: 2019/11/25 11:19:37 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int		count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
		count++;
	return (count);
}

t_gnl	*ft_create_list(int fd)
{
	t_gnl	*lst;

	if (fd < 0 || (!(lst = malloc(sizeof(t_gnl)))))
		return (NULL);
	lst->fd = fd;
	lst->content = ft_strdup("");
	lst->next = NULL;
	return (lst);
}

t_gnl	*ft_lstchr(t_gnl *list, int fd)
{
	while (list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	return (NULL);
}

t_gnl	*ft_lstadd(t_gnl **alst, t_gnl *new)
{
	if (alst)
		new->next = *alst;
	*alst = new;
	return (*alst);
}

char	*ft_strchr(const char *s, int c)
{
	int		count;

	count = -1;
	if (!s)
		return (NULL);
	while (s[++count])
		if (s[count] == c)
			return (char *)(s + count);
	if (s[count] == c)
		return (char *)(s + count);
	return (0);
}
