/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:34:49 by ellarbi           #+#    #+#             */
/*   Updated: 2020/01/14 15:34:51 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	pf_init		(t_pfinfo *list, const char *format)
**	@param:		struct pfinfo p, const char *format
**	@return:	init empty struct without malloc
*/

static	t_pfinfo	*pf_init(t_pfinfo *list, const char *format)
{
	list->flags = 0;
	list->width = 0;
	list->precision = 0;
	list->type = 0;
	list->content = NULL;
	list->count = 0;
	list->format = (char *)format;
	return (list);
}

/*
**	pf_convert	(struct pfinfo *p)
**	@param:			struct pfinfo p.
**	@description:	convert % after parsed
*/

void				pf_convert(t_pfinfo *p)
{
	p->type == '%' ? pf_convert_char(p, 1) : NULL;
	p->type == 'c' ? pf_convert_char(p, 0) : NULL;
	p->type == 'p' ? pf_convert_pointer(p) : NULL;
	p->type == 's' ? pf_convert_string(p) : NULL;
	p->type == 'n' ? pf_bind_ptr(p) : NULL;
	p->type == 'd' || p->type == 'i' ? pf_convert_dbonus(p) : NULL;
	pf_convert_bonus(p);
	p->flags = 0;
}

/*
**	pf_print	(int fd, struct pfinfo *p)
**	@param:		int fd, struct pfinfo p.
**	@return:	print and return size printed
*/

int					pf_print(int fd, t_pfinfo *p)
{
	size_t			output_size;
	t_pfcontent		*content;
	t_pfcontent		*next;

	output_size = 0;
	content = p->content;
	while (content)
	{
		next = content->next;
		write(fd, content->content, content->size);
		output_size += content->size;
		free(content->content);
		free(content);
		content = next;
	}
	return (output_size);
}

/*
**	ft_printf copy of printf.
**	@param:		const char *format, stargs ...
**	@return:	size printed by ft_dprintf.
*/

int					ft_printf(const char *format, ...)
{
	t_pfinfo	p;

	if (!ft_strchr(format, '%') && write(1, format, ft_strlen(format)))
		return (ft_strlen(format));
	pf_init(&p, format);
	va_start(p.va, format);
	while (ft_strchr(p.format + p.count, '%'))
	{
		pf_stradd(&p, ft_substr(format, p.count,
		ft_strchr_len(p.format + p.count, '%')));
		p.count += ft_strchr_len(p.format + p.count, '%');
		pf_parse(&p);
		pf_convert(&p);
	}
	pf_stradd(&p, ft_substr(format, p.count, ft_strlen(p.format + p.count)));
	va_end(p.va);
	return (pf_print(1, &p));
}

/*
**	ft_dprintf copy of dprintf.
**	@param:		int fd, const char *format, stargs ...
**	@return:	size printed by ft_dprintf.
*/

int					ft_dprintf(int fd, const char *format, ...)
{
	t_pfinfo	p;

	if (!ft_strchr(format, '%') && write(fd, format, ft_strlen(format)))
		return (ft_strlen(format));
	pf_init(&p, format);
	va_start(p.va, format);
	while (ft_strchr(p.format + p.count, '%'))
	{
		pf_stradd(&p, ft_substr(format, p.count,
		ft_strchr_len(p.format + p.count, '%')));
		p.count += ft_strchr_len(p.format + p.count, '%');
		pf_parse(&p);
		pf_convert(&p);
	}
	pf_stradd(&p, ft_substr(format, p.count, ft_strlen(p.format + p.count)));
	va_end(p.va);
	return (pf_print(fd, &p));
}
