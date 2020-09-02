/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params_to_default.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:19:18 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:19:19 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	textures_params(t_parameters *params)
{
	params->north_texture.id = NULL;
	params->north_texture.img = NULL;
	params->north_texture.width = 0;
	params->north_texture.height = 0;
	params->south_texture.id = NULL;
	params->south_texture.img = NULL;
	params->south_texture.width = 0;
	params->south_texture.height = 0;
	params->east_texture.id = NULL;
	params->east_texture.img = NULL;
	params->east_texture.width = 0;
	params->east_texture.height = 0;
	params->west_texture.id = NULL;
	params->west_texture.img = NULL;
	params->west_texture.width = 0;
	params->west_texture.height = 0;
	params->sprite_texture.id = NULL;
	params->sprite_texture.img = NULL;
	params->sprite_texture.width = 0;
	params->sprite_texture.height = 0;
}

void		set_params_to_default(t_parameters *params)
{
	params->win_id = NULL;
	params->img_id = NULL;
	params->img = NULL;
	params->win_h = 0;
	params->win_w = 0;
	params->map = NULL;
	params->sprites = NULL;
	params->posx = 0;
	params->posy = 0;
	params->dirx = 0;
	params->diry = 0;
	params->planex = 0;
	params->planey = 0;
	textures_params(params);
	params->floor_color = -1;
	params->ceiling_color = -1;
}
