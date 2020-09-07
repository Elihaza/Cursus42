/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 13:58:00 by ellarbi           #+#    #+#             */
/*   Updated: 2020/05/25 18:54:13 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_nb_char_block(const char *str)
{
	int		i;

	i = 0;
	if (str[i] == '%' && str[i + 1] == '%')
		return (2);
	i = 1;
	while (str[i] && !is_type(str[i]))
		i++;
	return (i + 1);
}

static void	init_block(t_block *block)
{
	block->to_convert = NULL;
	block->value = NULL;
	block->star[0] = NULL;
	block->star[1] = NULL;
	block->converted = NULL;
}

static void	handle_percent(int *i, const char *str)
{
	if (str[*i] == '%' && str[*i + 1] == '%')
	{
		*i += 2;
		return ;
	}
	else if (str[*i])
		(*i)++;
	while (str[*i] && !is_type(str[*i]))
		(*i)++;
	if (str[*i])
		(*i)++;
}

int			parsing(const char *str, t_list **lst)
{
	t_list		*new_elem;
	t_block		*block;
	int			i;

	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] != '%')
			i++;
		if (str[i] == '%')
		{
			if (!(block = malloc(sizeof(t_block))))
				return (-1);
			init_block(block);
			block->to_convert = ft_strndup(&str[i], get_nb_char_block(&str[i]));
			if (!(new_elem = ft_lstnew("", (void *)block)))
				return (-1);
			ft_lstadd_back(lst, new_elem);
		}
		handle_percent(&i, str);
	}
	return (1);
}
