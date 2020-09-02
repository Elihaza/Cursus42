/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:36:55 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:38:07 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	dda_data(t_dda_parameters *dda, t_parameters p, double *z)
{
	if (dda->side == NORTH || dda->side == SOUTH)
		dda->perpwalldist =
			(dda->mapx - p.posx + (1 - dda->stepx) / 2) / dda->raydirx;
	else
		dda->perpwalldist =
			(dda->mapy - p.posy + (1 - dda->stepy) / 2) / dda->raydiry;
	*z = dda->perpwalldist;
	dda->lineheight = (int)(p.win_h / dda->perpwalldist);
	dda->linex = -dda->lineheight / 2 + p.win_h / 2;
	dda->linex = dda->linex < 0 ? 0 : dda->linex;
	dda->liney = dda->lineheight / 2 + p.win_h / 2;
	dda->liney = dda->liney >= p.win_h ? p.win_h - 1 : dda->liney;
	if (dda->side == NORTH || dda->side == SOUTH)
		dda->wallx = p.posy + dda->perpwalldist * dda->raydiry;
	else
		dda->wallx = p.posx + dda->perpwalldist * dda->raydirx;
	dda->wallx -= floor(dda->wallx);
}
