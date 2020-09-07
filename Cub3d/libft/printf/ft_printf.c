/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:08:27 by ellarbi           #+#    #+#             */
/*   Updated: 2020/01/31 14:45:47 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			clear_block(void *content)
{
	t_block		*block;

	block = content;
	if (block->to_convert)
		free(block->to_convert);
	if (block->value && block->type != 's' && block->type != 'p')
		free(block->value);
	if (block->star[0])
		free(block->star[0]);
	if (block->star[1])
		free(block->star[1]);
	if (block->converted)
		free(block->converted);
	free(block);
}

static t_block	*skip_normal_char(t_list *lst, const char *str, int *i,
		int *nb_char)
{
	while (str[*i] && str[*i] != '%')
	{
		ft_putchar_fd(str[(*i)++], 1);
		(*nb_char)++;
	}
	if (lst)
		return (lst->content);
	else
		return (NULL);
}

static void		print_converted(t_block *block, int *nb_char)
{
	int		i;

	i = 0;
	if (block->type == 'c')
	{
		while (block->to_convert[i] && block->to_convert[i] != '-')
			i++;
		if (block->to_convert[i] == '-')
		{
			if ((*(int *)block->value) == '\0' && (*nb_char)++)
				ft_putchar_fd('\0', 1);
			ft_putstr_fd(block->converted, 1);
		}
		else
		{
			ft_putstr_fd(block->converted, 1);
			if ((*(int *)block->value) == '\0' && (*nb_char)++)
				ft_putchar_fd('\0', 1);
		}
	}
	else
		ft_putstr_fd(block->converted, 1);
	*nb_char += ft_strlen(block->converted);
}

static int		print_str(const char *str, t_list *lst)
{
	t_block		*block;
	int			nb_char;
	int			i;

	nb_char = 0;
	i = 0;
	while (str && str[i])
	{
		block = skip_normal_char(lst, str, &i, &nb_char);
		if (str[i] == '%')
		{
			print_converted(block, &nb_char);
			if (str[++i] == '%')
				;
			else
				while (str[i] && !is_type(str[i]))
					i++;
			i++;
			lst = lst->next;
		}
	}
	return (nb_char);
}

int				ft_printf(const char *str, ...)
{
	va_list	args;
	t_list	*lst;
	int		nb_printed_char;

	lst = NULL;
	va_start(args, str);
	if (parsing(str, &lst) == -1)
		return (-1);
	if (get_args(lst, args) == -1)
		return (-1);
	if (convert(lst) == -1)
		return (-1);
	if (apply_modifiers(lst) == -1)
		return (-1);
	va_end(args);
	nb_printed_char = print_str(str, lst);
	ft_lstclear(&lst, &clear_block);
	return (nb_printed_char);
}
