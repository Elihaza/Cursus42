/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_func1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:26:04 by ellarbi           #+#    #+#             */
/*   Updated: 2019/12/05 11:45:19 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_int(t_block *block)
{
	int		arg;

	arg = *((int *)block->value);
	if (!(block->converted = ft_itoa(arg)))
		return (-1);
	return (1);
}

int		convert_uint(t_block *block)
{
	unsigned int	arg;

	arg = *((unsigned int *)block->value);
	if (!(block->converted = utoa(arg)))
		return (-1);
	return (1);
}

int		convert_char(t_block *block)
{
	char	arg;

	arg = *((char *)block->value);
	if (!(block->converted = ft_strndup(&arg, 1)))
		return (-1);
	return (1);
}

int		convert_str(t_block *block)
{
	char	*arg;

	arg = (char *)block->value;
	if (arg)
	{
		if (!(block->converted = ft_strdup(arg)))
			return (-1);
	}
	else if (!(block->converted = ft_strdup("(null)")))
		return (-1);
	return (1);
}

int		convert_hex(t_block *block)
{
	unsigned int	arg;

	arg = *((unsigned int *)block->value);
	if (!(block->converted = utoa_base(arg, "0123456789abcdef")))
		return (-1);
	return (1);
}
