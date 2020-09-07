/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_modifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:34:23 by ellarbi           #+#    #+#             */
/*   Updated: 2019/12/05 22:36:39 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_flags(t_block *block, int *is_zero_flag, int *is_minus_flag)
{
	int		i;

	i = 0;
	while (block->to_convert[i])
	{
		if (block->to_convert[i] == '%')
			;
		else if (block->to_convert[i] == '0')
			*is_zero_flag = 1;
		else if (block->to_convert[i] == '-')
			*is_minus_flag = 1;
		else
			return ;
		i++;
	}
	return ;
}

int			apply_modifiers(t_list *lst)
{
	t_block		*block;
	int			is_zero_flag;
	int			is_minus_flag;

	while (lst)
	{
		is_zero_flag = 0;
		is_minus_flag = 0;
		block = (t_block *)lst->content;
		if (replace_stars(block) == -1)
			return (-1);
		get_flags(block, &is_zero_flag, &is_minus_flag);
		if (apply_precision(block) == -1)
			return (-1);
		if (apply_width(block, is_minus_flag, is_zero_flag) == -1)
			return (-1);
		lst = lst->next;
	}
	return (1);
}
