/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sprite_drawing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:48:57 by ellarbi           #+#    #+#             */
/*   Updated: 2020/07/20 08:11:39 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "build_image.h"
#include "../raycasting_engine/raycasting_engine.h"
#include <stdio.h>

static void	set_px(t_data *data, t_sprite *sprite, int *px, int line)
{
	int	sprite_texture_px;
	int	sprite_height;

	sprite_height = data->mlx.mlx_width / sprite->distance_from_player;
	if (line > data->mlx.mlx_height / 2 - sprite_height / 2 &&
			line < data->mlx.mlx_height / 2 + sprite_height / 2)
	{
		sprite_texture_px =
			((line - (data->mlx.mlx_height / 2 - sprite_height / 2)) *
			data->mlx.sprite_texture.height / sprite_height) *
			data->mlx.sprite_texture.height +
			(sprite->texture_column * data->mlx.sprite_texture.width);
		if (data->mlx.sprite_texture.data[sprite_texture_px])
			*px = data->mlx.sprite_texture.data[sprite_texture_px];
	}
}

int			get_sprite_color(t_data *data, t_column *column, int line, int *px)
{
	t_sprite	*sprite;
	t_list		*sprites;

	sprites = column->sprites;
	while (sprites && sprites->content)
	{
		sprite = sprites->content;
		set_px(data, sprite, px, line);
		sprites = sprites->next;
	}
	if (*px == 0x000000)
		return (0);
	return (1);
}
