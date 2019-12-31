/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_bonus.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/25 11:41:11 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/28 20:47:14 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void			pf_convert_dbonus(t_pfinfo *p)
{
	if (p->flags & (1 << 8) || p->flags & (1 << 9))
		return (pf_convert_decimal(p, p->flags & (1 << 9)
		? va_arg(p->va, long long) : va_arg(p->va, long)));
	else if (p->flags & (1 << 10) || p->flags & (1 << 11))
		return (pf_convert_decimal(p, p->flags & (1 << 11)
		? (char)va_arg(p->va, int) : (short)va_arg(p->va, int)));
	else
		pf_convert_decimal(p, va_arg(p->va, int));
}

void			pf_convert_bonus(t_pfinfo *p)
{
	if (p->type == 'x' || p->type == 'X')
	{
		if (p->flags & (1 << 8) || p->flags & (1 << 9))
			return (pf_convert_hexa(p, p->type == 'x'
			? LOW_HEXA : UP_HEXA, p->flags & (1 << 9)
			? va_arg(p->va, long long) : va_arg(p->va, long)));
		else if (p->flags & (1 << 10) || p->flags & (1 << 11))
			return (pf_convert_hexa(p, p->type == 'x'
				? LOW_HEXA : UP_HEXA, p->flags & (1 << 11)
	? (uint8_t)va_arg(p->va, uint32_t) : (uint16_t)va_arg(p->va, uint32_t)));
		else
			return (pf_convert_hexa(p, p->type == 'x'
			? LOW_HEXA : UP_HEXA, va_arg(p->va, unsigned int)));
	}
	else if (p->type == 'u')
	{
		if (p->flags & (1 << 8) || p->flags & (1 << 9))
			return (pf_convert_unsigned(p, p->flags & (1 << 9)
			? va_arg(p->va, long long) : va_arg(p->va, long)));
		else if (p->flags & (1 << 10) || p->flags & (1 << 11))
			return (pf_convert_unsigned(p, p->flags & (1 << 11)
	? (uint8_t)va_arg(p->va, uint32_t) : (uint16_t)va_arg(p->va, uint32_t)));
		else
			return (pf_convert_unsigned(p, va_arg(p->va, unsigned int)));
	}
}

void			pf_bind_ptr(t_pfinfo *p)
{
	t_pfcontent	*content;
	int			size;
	int			*ptr;

	if (!(ptr = va_arg(p->va, void *)))
		return ;
	content = p->content;
	size = 0;
	while (content)
	{
		size += content->size;
		content = content->next;
	}
	*ptr = size;
}
