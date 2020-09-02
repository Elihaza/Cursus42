/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:40:46 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:40:47 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_sprites(t_parameters *p)
{
	int x;
	int y;
	int i;

	p->nsprite = 0;
	x = -1;
	while (++x < p->map_h && (y = -1))
		while (++y < p->map_w)
			if ((p->map)[x][y] == '2')
				p->nsprite += 1;
	if (!(p->sprites = (t_sprite*)malloc(sizeof(t_sprite) * p->nsprite)))
		quit_program(p, "Set sprites: allocation failed.");
	x = -1;
	i = 0;
	while (++x < p->map_h && (y = -1))
		while (++y < p->map_w)
			if ((p->map)[x][y] == '2')
			{
				(p->sprites)[i].x = x;
				(p->sprites)[i].y = y;
				i++;
			}
}
