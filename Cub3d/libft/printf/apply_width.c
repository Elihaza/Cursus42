/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:42:16 by frdescam          #+#    #+#             */
/*   Updated: 2019/12/05 16:20:07 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	apply_width_to_str(t_block *block, int width, int is_minus_flag)
{
	int		converted_len;
	char	*add;
	char	*tmp;

	converted_len = ft_strlen(block->converted);
	if (width > converted_len)
	{
		if (!(add = malloc(sizeof(char) * (width - converted_len + 1))))
			return (-1);
		ft_memset(add, ' ', width - converted_len);
		add[width - converted_len] = '\0';
		if (is_minus_flag)
		{
			if (!(tmp = ft_strjoin(block->converted, add)))
				return (-1);
		}
		else if (!(tmp = ft_strjoin(add, block->converted)))
			return (-1);
		free(add);
		free(block->converted);
		block->converted = tmp;
	}
	return (1);
}

int			apply_width(t_block *block, int is_minus_flag,
		int is_zero_flag)
{
	int		width;
	int		i;

	i = 0;
	while (block->to_convert[i] && (block->to_convert[i] == '%' ||
				block->to_convert[i] == '-' || block->to_convert[i] == '0'))
		i++;
	width = ft_atoi(&(block->to_convert[i]));
	if (block->type == 'i' || block->type == 'd' || block->type == 'x' ||
			block->type == 'X' || block->type == 'u' || block->type == 'c'
			|| block->type == 'p' || block->type == '%')
		if (apply_width_to_int(block, width,
					is_minus_flag, is_zero_flag) == -1)
			return (-1);
	if (block->type == 's')
		if (apply_width_to_str(block, width, is_minus_flag) == -1)
			return (-1);
	while (ft_isdigit(block->to_convert[i]))
		i++;
	return (1);
}
