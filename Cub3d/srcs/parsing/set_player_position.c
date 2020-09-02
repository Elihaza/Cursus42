/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 17:03:29 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/25 13:45:50 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_player_position(t_parameters *params, int c, int x, int y)
{
	if (params->posx != 0 && params->posy != 0)
		quit_program(params, "player position already set.");
	params->posx = x + 0.5;
	params->posy = y + 0.5;
	(params->map)[x][y] = '0';
	if (c == NORTH)
	{
		params->dirx = -1;
		params->planey = 0.66;
	}
	if (c == SOUTH)
	{
		params->dirx = 1;
		params->planey = -0.66;
	}
	if (c == EAST)
	{
		params->diry = 1;
		params->planex = 0.66;
	}
	if (c == WEST)
	{
		params->diry = -1;
		params->planex = -0.66;
	}
}
