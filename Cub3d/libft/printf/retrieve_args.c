/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   retrieve_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:17:49 by frdescam          #+#    #+#             */
/*   Updated: 2019/11/12 10:50:35 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		retrieve_int(void **out, va_list args)
{
	int		*out_i;

	if (!(out_i = malloc(sizeof(int))))
		return (-1);
	*out_i = va_arg(args, int);
	*out = out_i;
	return (1);
}

int		retrieve_uint(void **out, va_list args)
{
	int		*out_u;

	if (!(out_u = malloc(sizeof(unsigned int))))
		return (-1);
	*out_u = va_arg(args, unsigned int);
	*out = out_u;
	return (1);
}

int		retrieve_ptr(void **out, va_list args)
{
	*out = va_arg(args, void *);
	return (1);
}
