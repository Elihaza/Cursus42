/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:43:15 by frdescam          #+#    #+#             */
/*   Updated: 2020/07/25 13:40:39 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	move_smallest_before_tmp(t_list *to_move_prev,
		t_list *dest, t_list *dest_prev, t_list **lst)
{
	t_list	*to_move;

	to_move = to_move_prev->next;
	if (dest_prev)
		dest_prev->next = to_move;
	else
		*lst = to_move;
	to_move_prev->next = to_move->next;
	to_move->next = dest;
}

static void	get_smallest(t_list **smallest, t_list **smallest_prev,
		int (*f)(void *content1, void *content2))
{
	t_list	*current;
	t_list	*current_prev;

	current = *smallest;
	current_prev = *smallest_prev;
	while (current)
	{
		if (f((*smallest)->content, current->content))
		{
			*smallest = current;
			*smallest_prev = current_prev;
		}
		current_prev = current;
		current = current->next;
	}
}

void		ft_lstsort(t_list **lst, int (*f)(void *content1, void *content2))
{
	t_list	*smallest;
	t_list	*smallest_prev;
	t_list	*tmp;
	t_list	*tmp_prev;

	tmp = *lst;
	smallest = *lst;
	smallest_prev = NULL;
	tmp_prev = NULL;
	while (tmp)
	{
		smallest = tmp;
		smallest_prev = tmp_prev;
		get_smallest(&smallest, &smallest_prev, f);
		if (tmp == smallest)
		{
			tmp_prev = tmp;
			tmp = tmp->next;
		}
		else
		{
			move_smallest_before_tmp(smallest_prev, tmp, tmp_prev, lst);
			tmp_prev = smallest;
		}
	}
}
/*
**#include "stdio.h"
**
**int		f(void *content1, void *content2)
**{
**	if (atoi(content1) > atoi(content2))
**		return (1);
**	return (0);
**}
**
**int		main(void)
**{
**	t_list	*lst1;
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
**	str1 = ft_strdup("1");
**	str2 = ft_strdup("2");
**	str3 = ft_strdup("3");
**	str4 = ft_strdup("4");
**	str5 = ft_strdup("5");
**	str6 = ft_strdup("6");
**	str7 = ft_strdup("7");
**	new_elem = ft_lstnew(str5);
**	ft_lstadd_back(&lst1, new_elem);
**	new_elem = ft_lstnew(str7);
**	ft_lstadd_back(&lst1, new_elem);
**	new_elem = ft_lstnew(str3);
**	ft_lstadd_back(&lst1, new_elem);
**	new_elem = ft_lstnew(str4);
**	ft_lstadd_back(&lst1, new_elem);
**	new_elem = ft_lstnew(str1);
**	ft_lstadd_back(&lst1, new_elem);
**	new_elem = ft_lstnew(str2);
**	ft_lstadd_back(&lst1, new_elem);
**	new_elem = ft_lstnew(str6);
**	ft_lstadd_back(&lst1, new_elem);
**
**	t_list	*lst1_tmp = lst1;
**	while (lst1_tmp)
**	{
**		printf("%s\n", lst1_tmp->content);
**		lst1_tmp = lst1_tmp->next;
**	}
**	ft_lstsort(&lst1, &f);
**	printf("\n\n");
**	lst1_tmp = lst1;
**	while (lst1_tmp)
**	{
**		printf("%s\n", lst1_tmp->content);
**		lst1_tmp = lst1_tmp->next;
**	}
**}
*/
