/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:35:22 by ellarbi           #+#    #+#             */
/*   Updated: 2020/01/14 15:35:23 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	pf_parse_flags(struct printf_infos)
**	@description:		parse flags and put in @param
**	@param:				struct t_pfinfo
*/

static	void			pf_parse_flags(t_pfinfo *p)
{
	while (p->format[p->count] && ft_strchr(PF_FLAGS, p->format[p->count]))
	{
		if (p->format[p->count] == '-')
			p->flags |= (1 << 0);
		else if (p->format[p->count] == '+')
			p->flags |= (1 << 5);
		else if (p->format[p->count] == '0')
			p->flags |= (1 << 1);
		else if (p->format[p->count] == '#')
			p->flags |= (1 << 7);
		else if (p->format[p->count] == ' ')
			p->flags |= (1 << 6);
		p->count++;
	}
}

/*
**	pf_parse_size(struct printf_infos)
**	@description:		parse size and put in @param
**	@param:				struct t_pfinfo
*/

static	void			pf_parse_size(t_pfinfo *p)
{
	if (p->format[p->count] == '*')
	{
		p->flags |= (1 << 4);
		p->width = va_arg(p->va, int);
		p->count++;
	}
	else if (ft_isdigit(p->format[p->count]))
	{
		p->flags |= (1 << 4);
		p->width = ft_atoi(p->format + p->count);
		p->count += ft_numlen(p->width);
	}
	if (p->format[p->count] == '.' && (p->flags |= (1 << 3)))
	{
		p->count++;
		if (p->format[p->count] == '*' && (p->count++))
			p->precision = va_arg(p->va, int);
		else if (ft_isdigit(p->format[p->count]))
		{
			p->precision = ft_atoi(p->format + p->count);
			while (ft_isdigit(p->format[p->count]))
				p->count++;
		}
	}
}

/*
**	pf_parse_type(struct printf_infos)
**	@description:		parse type with bonus "l,ll,h,hh"
**	@param:				struct t_pfinfo
*/

static	void			pf_parse_type(t_pfinfo *p)
{
	while (p->format[p->count] && ft_strchr(PF_MF, p->format[p->count]))
	{
		if (p->format[p->count] == 'l')
		{
			if (p->format[p->count + 1] == 'l')
				p->flags |= (1 << 9);
			else
				p->flags |= (1 << 8);
		}
		if (p->format[p->count] == 'h')
		{
			if (p->format[p->count + 1] == 'h')
				p->flags |= (1 << 11);
			else
				p->flags |= (1 << 10);
		}
		p->count++;
	}
	p->type = p->format[p->count];
	p->count++;
}

/*
**	pf_parse(struct printf_infos)
**	@description:		parse format for ft_printf
**	@param:				struct t_pfinfo
*/

void					pf_parse(t_pfinfo *p)
{
	if (p->format[p->count] == '%')
		p->count++;
	pf_parse_flags(p);
	pf_parse_size(p);
	pf_parse_type(p);
	if (p->width < 0)
	{
		p->width *= -1;
		p->flags |= (1 << 0);
	}
	if (p->precision < 0)
		p->flags &= ~(1 << 3);
}
