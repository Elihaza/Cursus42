/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:36:48 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:36:49 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	dda_init(t_parameters p, t_dda_parameters *dda, int screen_slice)
{
	dda->camerax = 2 * screen_slice / (double)p.win_w - 1;
	dda->raydirx = p.dirx + p.planex * dda->camerax;
	dda->raydiry = p.diry + p.planey * dda->camerax;
	dda->mapx = (int)p.posx;
	dda->mapy = (int)p.posy;
	dda->deltadistx = fabs(1 / dda->raydirx);
	dda->deltadisty = fabs(1 / dda->raydiry);
	dda->stepx = dda->raydirx < 0 ? -1 : 1;
	if (dda->raydirx < 0)
		dda->sidedistx = (p.posx - dda->mapx) * dda->deltadistx;
	else
		dda->sidedistx = (dda->mapx + 1.0 - p.posx) * dda->deltadistx;
	dda->stepy = dda->raydiry < 0 ? -1 : 1;
	if (dda->raydiry < 0)
		dda->sidedisty = (p.posy - dda->mapy) * dda->deltadisty;
	else
		dda->sidedisty = (dda->mapy + 1.0 - p.posy) * dda->deltadisty;
}
