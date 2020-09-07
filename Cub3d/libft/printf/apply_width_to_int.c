/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width_to_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 14:15:39 by ellarbi           #+#    #+#             */
/*   Updated: 2019/12/06 23:36:34 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	as_precision(t_block *block)
{
	int	i;

	i = 0;
	while (block->to_convert[i] && block->to_convert[i] != '.')
		i++;
	if (block->to_convert[i] == '.')
		return (1);
	return (0);
}

static int	get_precision(t_block *block)
{
	int	i;
	int	precision;

	i = 0;
	while (block->to_convert[i] && block->to_convert[i] != '.')
		i++;
	i++;
	precision = ft_atoi(&block->to_convert[i]);
	return (precision);
}

static void	handle_minus(t_block *block, int is_zero_flag)
{
	int		i;

	if (is_zero_flag && (get_precision(block) < 0 ||
				!as_precision(block)))
	{
		i = 0;
		while (block->converted[i] && block->converted[i] != '-')
			i++;
		if (block->converted[i] == '-')
		{
			block->converted[i] = '0';
			block->converted[0] = '-';
		}
	}
}

static	int	get_converted_len(t_block *block)
{
	int		converted_len;

	converted_len = ft_strlen(block->converted);
	if (block->type == 'c' && (*(char *)block->value) == '\0')
		converted_len++;
	return (converted_len);
}

int			apply_width_to_int(t_block *block, int width, int is_minus_flag,
		int is_zero_flag)
{
	int		converted_len;
	char	*add;
	char	*tmp;

	converted_len = get_converted_len(block);
	if (width > converted_len)
	{
		if (!(add = malloc(sizeof(char) * (width - converted_len + 1))))
			return (-1);
		if (is_zero_flag && !is_minus_flag && (get_precision(block) < 0 ||
					!as_precision(block)))
			ft_memset(add, '0', width - converted_len);
		else
			ft_memset(add, ' ', width - converted_len);
		add[width - converted_len] = '\0';
		if (is_minus_flag)
			tmp = ft_strjoin(block->converted, add);
		else if (!(tmp = ft_strjoin(add, block->converted)))
			return (-1);
		free(add);
		free(block->converted);
		block->converted = tmp;
		handle_minus(block, is_zero_flag);
	}
	return (1);
}
