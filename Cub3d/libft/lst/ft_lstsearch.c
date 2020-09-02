/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:40:41 by frdescam          #+#    #+#             */
/*   Updated: 2020/07/25 13:39:01 by frdescam         ###   ########.fr       */
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

/*
**#include <stdio.h>
**
**int		main(void)
**{
**	t_list	*lst;
**	t_list	*lst_tmp;
**	t_list	*new_elem;
**	char	*str1;
**	char	*str2;
**	char	*str3;
**	char	*str4;
**	char	*str5;
**	char	*str6;
**	char	*str7;
**
**	lst = NULL;
**	str1 = ft_strdup("content1");
**	str2 = ft_strdup("content2");
**	str3 = ft_strdup("content3");
**	str4 = ft_strdup("content4");
**	str5 = ft_strdup("content5");
**	str6 = ft_strdup("content6");
**	str7 = ft_strdup("content7");
**	new_elem = ft_lstnew("str1", str1);
**	ft_lstadd_back(&lst, new_elem);
**	new_elem = ft_lstnew("str2", str2);
**	ft_lstadd_back(&lst, new_elem);
**	new_elem = ft_lstnew("str3", str3);
**	ft_lstadd_back(&lst, new_elem);
**	new_elem = ft_lstnew("str4", str4);
**	ft_lstadd_back(&lst, new_elem);
**	new_elem = ft_lstnew("str5", str5);
**	ft_lstadd_back(&lst, new_elem);
**	new_elem = ft_lstnew("str6", str6);
**	ft_lstadd_back(&lst, new_elem);
**	new_elem = ft_lstnew("str7", str7);
**	ft_lstadd_back(&lst, new_elem);
**
**	lst_tmp = lst;
**	while (lst_tmp)
**	{
**		printf("name : %s, content : %s\n", lst->name, (char *)lst->content);
**		lst_tmp = lst_tmp->next;
**	}
**	printf("\n\n");
**	printf("searching for %s, found : name=%s, content=%s\n", "str2",
**			ft_lstsearch(lst, "str2")->name,
**			(char *)(ft_lstsearch(lst, "str2")->content));
**	printf("searching for %s, found : name=%s, content=%s\n", "str4",
**			ft_lstsearch(lst, "str4")->name,
**			(char *)(ft_lstsearch(lst, "str4")->content));
**	printf("searching for %s, found : name=%s,
**			content=%s\n", "str3", ft_lstsearch(lst, "str3")->name,
**			(char *)(ft_lstsearch(lst, "str3")->content));
**	printf("searching for %s, found : name=%s,
**			content=%s\n", "str6", ft_lstsearch(lst, "str6")->name,
**			(char *)(ft_lstsearch(lst, "str6")->content));
**}
*/
