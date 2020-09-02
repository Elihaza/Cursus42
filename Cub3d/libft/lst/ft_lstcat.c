/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 11:54:16 by frdescam          #+#    #+#             */
/*   Updated: 2020/03/09 18:20:24 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstcat(t_list **lst1, t_list **lst2)
{
	t_list	*last;

	if (!*lst1)
	{
		*lst1 = *lst2;
		return ;
	}
	last = ft_lstlast(*lst1);
	last->next = *lst2;
}
/*
**#include <stdio.h>
**
**int		main(void)
**{
**	t_list	*lst1;
**	t_list	*lst2;
**	t_list	*new_elem;
**	char	*str1;
**	char	*str2;
**	char	*str3;
**	char	*str4;
**	char	*str5;
**	char	*str6;
**	char	*str7;
**
**	lst1 = NULL;
**	lst2 = NULL;
**	str1 = ft_strdup("str1");
**	str2 = ft_strdup("str2");
**	str3 = ft_strdup("str3");
**	str4 = ft_strdup("str4");
**	str5 = ft_strdup("str5");
**	str6 = ft_strdup("str6");
**	str7 = ft_strdup("str7");
**	new_elem = ft_lstnew(str1);
**	ft_lstadd_back(&lst1, new_elem);
**	new_elem = ft_lstnew(str2);
**	ft_lstadd_back(&lst1, new_elem);
**	new_elem = ft_lstnew(str3);
**	ft_lstadd_back(&lst1, new_elem);
**	new_elem = ft_lstnew(str4);
**	ft_lstadd_back(&lst1, new_elem);
**	new_elem = ft_lstnew(str5);
**	ft_lstadd_back(&lst2, new_elem);
**	new_elem = ft_lstnew(str6);
**	ft_lstadd_back(&lst2, new_elem);
**	new_elem = ft_lstnew(str7);
**	ft_lstadd_back(&lst2, new_elem);
**
**	t_list	*lst1_tmp = lst1;
**	t_list	*lst2_tmp = lst2;
**	while (lst1_tmp)
**	{
**		printf("%s\n", lst1_tmp->content);
**		lst1_tmp = lst1_tmp->next;
**	}
**	printf("\n\n");
**	while (lst2_tmp)
**	{
**		printf("%s\n", lst2_tmp->content);
**		lst2_tmp = lst2_tmp->next;
**	}
**	ft_lstcat(lst1, lst2);
**	while (lst1)
**	{
**		printf("%s\n", lst1->content);
**		lst1 = lst1->next;
**	}
**}
*/
