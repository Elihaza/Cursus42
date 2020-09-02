/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:16:44 by ellarbi           #+#    #+#             */
/*   Updated: 2019/11/28 19:22:08 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	retrieve_arg(t_block *block, va_list args, int i)
{
	if (block->to_convert[i] == 's' || block->to_convert[i] == 'p')
	{
		if (!(retrieve_ptr(&block->value, args)))
			return (-1);
		block->type = block->to_convert[i];
	}
	else if (block->to_convert[i] == 'u')
	{
		if (!(retrieve_uint(&block->value, args)))
			return (-1);
		block->type = block->to_convert[i];
	}
	else if (block->to_convert[i] == 'c' || block->to_convert[i] == 'x' ||
			block->to_convert[i] == 'X' || block->to_convert[i] == 'd' ||
			block->to_convert[i] == 'i')
	{
		if (!(retrieve_int(&block->value, args)))
			return (-1);
		block->type = block->to_convert[i];
	}
	else if (block->to_convert[i] == '%')
		if (convert_mod(block) == -1)
			return (-1);
	return (1);
}

int			get_block_args(t_block *block, va_list args)
{
	int		i;
	int		nb_stars;

	i = 1;
	nb_stars = 0;
	while (block->to_convert[i])
	{
		while (block->to_convert[i] && block->to_convert[i] != '%' &&
				block->to_convert[i] != '*' && !is_type(block->to_convert[i]))
			i++;
		if (is_type(block->to_convert[i]))
			if (retrieve_arg(block, args, i) == -1)
				return (-1);
		if (block->to_convert[i] == '*')
		{
			if (retrieve_int((void **)(&block->star[nb_stars]), args) == -1)
				return (-1);
			nb_stars++;
		}
		i++;
	}
	return (1);
}

int			get_args(t_list *lst, va_list args)
{
	t_block		*block;

	while (lst)
	{
		block = lst->content;
		if (get_block_args(block, args) == -1)
			return (-1);
		lst = lst->next;
	}
	return (1);
}
