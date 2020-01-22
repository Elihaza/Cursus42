/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:35:06 by ellarbi           #+#    #+#             */
/*   Updated: 2020/01/14 15:35:10 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	pf_convert_uminus 	:: static void (struct printf_info)
**	@description:	converter functions for unsigned int with flag '-'
**	@params:		struct t_pfinfo *p
*/

static void		pf_convert_uminus(t_pfinfo *p, char *str)
{
	int				len;

	if (p->flags & (1 << 3) && p->precision
	&& p->precision > (int)ft_strlen(str))
		pf_addzeros(p, (int)ft_strlen(str) - p->precision);
	pf_stradd(p, str);
	len = ft_strlen(str);
	if (p->precision > (int)ft_strlen(str))
		len = p->precision;
	if (p->flags & (1 << 4) && p->width > (int)ft_strlen(str) &&
	!(p->flags & (1 << 3) || p->precision))
		return (pf_addspaces(p, p->width - (ft_strlen(str))));
	if (p->flags & (1 << 4) && p->width >= len)
		return (pf_addspaces(p, p->width - len));
}

/*
**	pf_convert_unsigned 	:: static void (struct printf_info, number)
**	@description:	converter functions for unsigned integer.
**	@params:		struct t_pfinfo *p
*/

void			pf_convert_unsigned(t_pfinfo *p, long long number)
{
	const	char		*str = ft_ulltoa_base(number, DEC_BASE);
	int					len;

	if (!p->flags)
		return (pf_stradd(p, (char *)str));
	if (p->flags & (1 << 3) && !p->precision && !number)
	{
		free((char *)str);
		return (pf_addspaces(p, p->width));
	}
	if (p->flags & (1 << 0))
		return (pf_convert_uminus(p, (char *)str));
	len = ft_strlen(str);
	if (p->precision > (int)ft_strlen(str))
		len = p->precision;
	if (p->flags & (1 << 4) && p->width >= len &&
	(!(p->flags & (1 << 1)) || p->flags & (1 << 3)))
		pf_addspaces(p, p->width - len);
	if (p->flags & (1 << 4) && p->width >= len
	&& p->flags & (1 << 1) && !(p->flags & (1 << 3)))
		pf_addzeros(p, p->width - len);
	if (p->flags & (1 << 3) && p->precision > (int)ft_strlen(str))
		pf_addzeros(p, ft_strlen(str) - p->precision);
	return (pf_stradd(p, (char *)str));
}

/*
**	pf_convert_pointer 	:: static void (struct printf_info)
**	@description:	converter functions for pointer and address
**	@params:		struct t_pfinfo *p
*/

void			pf_convert_pointer(t_pfinfo *p)
{
	const	intptr_t	ptr = (intptr_t)va_arg(p->va, void *);
	char				*str;

	if (p->flags & (1 << 3) && !ptr)
		str = ft_strdup("0x");
	else
		str = ft_strjoin(ft_strdup("0x"),
		ft_ulltoa_base((unsigned long long)ptr, LOW_HEXA));
	if (p->flags & (1 << 4) && !(p->flags & (1 << 0))
	&& p->width > (int)ft_strlen(str))
		pf_addspaces(p, p->width - ft_strlen(str));
	pf_stradd(p, str);
	if (p->flags & (1 << 4) && p->flags & (1 << 0)
	&& p->width > (int)ft_strlen(str))
		pf_addspaces(p, p->width - ft_strlen(str));
}

/*
**	pf_convert_char 	:: static void (struct printf_info, bool is_pourcent)
**	@description:	converter functions for char and %
**	@params:		struct t_pfinfo *p
*/

void			pf_convert_char(t_pfinfo *p, int is_pourcent)
{
	const char	c = is_pourcent ? '%' : va_arg(p->va, int);

	if (p->flags & (1 << 0))
	{
		pf_charadd(p, c);
		if (p->width > 1)
			pf_addspaces(p, p->width - 1);
		return ;
	}
	if (p->width > 1 && p->flags & (1 << 1))
		pf_addzeros(p, p->width - 1);
	else if (p->flags & (1 << 4) && p->width > 1)
		pf_addspaces(p, p->width - 1);
	pf_charadd(p, c);
}

/*
**	pf_convert_string 	:: static void (struct printf_info)
**	@description:	converter functions for string.
**	@params:		struct t_pfinfo *p
*/

void			pf_convert_string(t_pfinfo *p)
{
	char	*str;

	str = va_arg(p->va, char *);
	if (!str)
		str = "(null)";
	str = ft_strdup(str);
	if (!p->flags)
		return (pf_stradd(p, str));
	if (p->flags & (1 << 3))
		str = ft_strncpy(ft_calloc(p->precision + 1, sizeof(char)), str,
		p->precision);
	if (p->flags & (1 << 0))
	{
		pf_stradd(p, str);
		if (p->flags & (1 << 4) && p->width > (int)ft_strlen(str))
			pf_addspaces(p, p->width - (int)ft_strlen(str));
		return ;
	}
	if (p->flags & (1 << 4) && p->width > (int)ft_strlen(str))
		pf_addspaces(p, p->width - (int)ft_strlen(str));
	pf_stradd(p, str);
}
