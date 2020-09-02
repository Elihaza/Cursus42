/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:19:12 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/23 13:09:49 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	validate_map_params(t_parameters *p)
{
	if (p->map_h < 3 || p->map_w < 3)
		return (0);
	if (p->map == NULL)
		return (0);
	return (1);
}

static int	validate_start_position(t_parameters *p)
{
	if (p->posx == 0 && p->posy == 0)
		return (0);
	if (p->dirx == 0 && p->diry == 0)
		return (0);
	if (p->planex == 0 && p->planey == 0)
		return (0);
	return (1);
}

static int	validate_texture(t_texture t)
{
	if (!t.img || t.width <= 0 || t.height <= 0)
		return (0);
	return (1);
}

static int	validate_textures(t_parameters *p)
{
	if (!validate_texture(p->north_texture))
		return (0);
	if (!validate_texture(p->south_texture))
		return (0);
	if (!validate_texture(p->west_texture))
		return (0);
	if (!validate_texture(p->east_texture))
		return (0);
	if (!validate_texture(p->sprite_texture))
		return (0);
	return (1);
}

int			validate_params(t_parameters *params)
{
	if (params->win_h <= 0 || params->win_w <= 0)
		return (0);
	if (!validate_map_params(params))
		return (0);
	if (!validate_start_position(params))
		return (0);
	if (!validate_textures(params))
		return (0);
	if (params->floor_color == -1 || params->ceiling_color == -1)
		return (0);
	return (1);
}
