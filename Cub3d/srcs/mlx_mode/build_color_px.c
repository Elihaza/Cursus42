/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_color_px.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:10:12 by ellarbi           #+#    #+#             */
/*   Updated: 2020/07/16 14:25:49 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "build_image.h"

int		get_texture_px(t_texture_img *texture, t_column *column, int line)
{
	double	ray_block_x;
	int		texture_px;

	ray_block_x = 0.0;
	if (column->wall_orientation == 'N')
		ray_block_x = 1. - (column->impact_x - (int)column->impact_x);
	else if (column->wall_orientation == 'S')
		ray_block_x = column->impact_x - (int)column->impact_x;
	else if (column->wall_orientation == 'E')
		ray_block_x = 1. - (column->impact_y - (int)column->impact_y);
	else if (column->wall_orientation == 'W')
		ray_block_x = column->impact_y - (int)column->impact_y;
	texture_px = line * texture->width + (int)(ray_block_x * texture->width);
	return (texture->data[texture_px]);
}

int		get_sky_color(t_data *data)
{
	return (data->color_textures.sky);
}

int		get_floor_color(t_data *data)
{
	return (data->color_textures.floor);
}

int		get_wall_color(t_data *data, t_column *column, int line)
{
	if (column->wall_orientation == 'N')
		if (!data->textures_paths.north)
			return (0xff0000);
		else
			return (get_texture_px(&data->mlx.north_texture, column,
				line * data->mlx.north_texture.height / column->height));
	else if (column->wall_orientation == 'S')
		if (!data->textures_paths.south)
			return (0xffff00);
		else
			return (get_texture_px(&data->mlx.south_texture, column,
				line * data->mlx.south_texture.height / column->height));
	else if (column->wall_orientation == 'E')
		if (!data->textures_paths.east)
			return (0x0000ff);
		else
			return (get_texture_px(&data->mlx.east_texture, column,
				line * data->mlx.east_texture.height / column->height));
	else if (!data->textures_paths.west)
		return (0xffffff);
	else
		return (get_texture_px(&data->mlx.west_texture, column,
				line * data->mlx.west_texture.height / column->height));
}
