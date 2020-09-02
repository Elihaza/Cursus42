/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:13:18 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:13:20 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	camera_left(t_parameters *p)
{
	double olddirx;
	double oldplanex;

	olddirx = p->dirx;
	p->dirx = p->dirx * cos(ROTSPEED) - p->diry * sin(ROTSPEED);
	p->diry = olddirx * sin(ROTSPEED) + p->diry * cos(ROTSPEED);
	oldplanex = p->planex;
	p->planex = p->planex * cos(ROTSPEED) - p->planey * sin(ROTSPEED);
	p->planey = oldplanex * sin(ROTSPEED) + p->planey * cos(ROTSPEED);
}
