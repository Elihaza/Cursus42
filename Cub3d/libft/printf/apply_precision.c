/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:36:51 by ellarbi           #+#    #+#             */
/*   Updated: 2019/12/05 14:08:37 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	apply_precision_to_str(t_block *block, int precision)
{
	int		converted_len;
	char	*tmp;

	converted_len = ft_strlen(block->converted);
	if (converted_len > precision && block->type == 's' && precision >= 0)
	{
		if (!(tmp = malloc(sizeof(char) * (precision + 1))))
			return (-1);
		ft_strlcpy(tmp, block->converted, precision + 1);
		free(block->converted);
		block->converted = tmp;
	}
	return (1);
}

static int	remove_minus(t_block *block, int *is_minus_removed)
{
	char	*tmp;

	*is_minus_removed = 0;
	if (block->converted[0] == '-')
	{
		if (!(tmp = ft_strdup(&block->converted[1])))
			return (-1);
		free(block->converted);
		block->converted = tmp;
		*is_minus_removed = 1;
	}
	return (1);
}

static int	apply_precision_to_int2(t_block *block, int precision,
		int is_minus_removed)
{
	char	*tmp;

	if (precision == 0 && block->type != 'p' &&
			*((int *)block->value) == 0)
	{
		block->converted[0] = '\0';
		return (1);
	}
	if (is_minus_removed)
	{
		if (!(tmp = ft_strjoin("-", block->converted)))
			return (-1);
		free(block->converted);
		block->converted = tmp;
	}
	if (block->type == 'p' && precision == 0 && (long)block->value == 0)
	{
		free(block->converted);
		block->converted = ft_strdup("0x");
	}
	return (1);
}

static int	apply_precision_to_int(t_block *block, int precision)
{
	char	*add;
	char	*tmp;
	int		converted_len;
	int		is_minus_removed;

	if (!(remove_minus(block, &is_minus_removed)))
		return (-1);
	converted_len = ft_strlen(block->converted);
	if (precision > converted_len)
	{
		if (!(add = malloc(sizeof(char) * (precision - converted_len + 1))))
			return (-1);
		ft_memset(add, '0', precision - converted_len);
		add[precision - converted_len] = '\0';
		if (!(tmp = ft_strjoin(add, block->converted)))
			return (-1);
		free(add);
		free(block->converted);
		block->converted = tmp;
	}
	return (apply_precision_to_int2(block, precision, is_minus_removed));
}

int			apply_precision(t_block *block)
{
	int		precision;
	int		i;

	i = 0;
	while (block->to_convert[i] && block->to_convert[i] != '.')
		i++;
	if (block->to_convert[i] == '\0')
		return (1);
	i++;
	precision = ft_atoi(&(block->to_convert[i]));
	if (block->type == 'i' || block->type == 'd' || block->type == 'x' ||
			block->type == 'X' || block->type == 'u' || block->type == 'c'
			|| block->type == 'p')
		if (apply_precision_to_int(block, precision) == -1)
			return (-1);
	if (block->type == 's' || block->type == '%')
		if (apply_precision_to_str(block, precision) == -1)
			return (-1);
	return (1);
}
