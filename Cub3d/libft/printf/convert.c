/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 10:52:02 by ellarbi           #+#    #+#             */
/*   Updated: 2019/12/04 15:37:04 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert3(t_block *block)
{
	if (block->type == 'i' || block->type == 'd')
	{
		if (convert_int(block) == -1)
			return (-1);
	}
	else if (block->type == '%')
		if (convert_mod(block) == -1)
			return (-1);
	return (1);
}

int		convert2(t_block *block)
{
	if (block->type == 'u')
	{
		if (convert_uint(block) == -1)
			return (-1);
	}
	else if (block->type == 'x')
	{
		if (convert_hex(block) == -1)
			return (-1);
	}
	else if (block->type == 'X')
	{
		if (convert_uphex(block) == -1)
			return (-1);
	}
	else if (block->type == 'p')
	{
		if (convert_ptr(block) == -1)
			return (-1);
	}
	else if (convert3(block) == -1)
		return (-1);
	return (1);
}

int		convert(t_list *lst)
{
	t_block		*block;

	while (lst)
	{
		block = lst->content;
		if (block->type == 'c')
		{
			if (convert_char(block) == -1)
				return (-1);
		}
		else if (block->type == 's')
		{
			if (convert_str(block) == -1)
				return (-1);
		}
		else if (convert2(block) == -1)
			return (-1);
		lst = lst->next;
	}
	return (1);
}
