/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_func2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 23:27:23 by ellarbi           #+#    #+#             */
/*   Updated: 2019/12/05 11:45:47 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		convert_uphex(t_block *block)
{
	unsigned int	arg;

	arg = *((unsigned int *)block->value);
	if (!(block->converted = utoa_base(arg, "0123456789ABCDEF")))
		return (-1);
	return (1);
}

int		convert_ptr(t_block *block)
{
	void	*arg;
	char	*tmp;

	arg = block->value;
	if (!(block->converted = ft_ltoa_base((unsigned long)arg,
					"0123456789abcdef")))
		return (-1);
	if (!(tmp = ft_strjoin("0x", block->converted)))
		return (-1);
	free(block->converted);
	block->converted = tmp;
	return (1);
}

int		convert_mod(t_block *block)
{
	free(block->converted);
	if (!(block->converted = ft_strndup(&block->type, 1)))
		return (-1);
	block->type = '%';
	return (1);
}
