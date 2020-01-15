/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:35:32 by ellarbi           #+#    #+#             */
/*   Updated: 2020/01/14 15:35:34 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		pf_addspaces(t_pfinfo *p, int width)
{
	if (width < 0)
		width *= -1;
	pf_stradd(p, ft_memset(ft_calloc(width + 1, sizeof(char)), ' ', width));
}

void		pf_addzeros(t_pfinfo *p, int width)
{
	if (width < 0)
		width *= -1;
	pf_stradd(p, ft_memset(ft_calloc(width + 1, sizeof(char)), '0', width));
}
