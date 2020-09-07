/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:28:22 by ellarbi           #+#    #+#             */
/*   Updated: 2020/07/16 16:09:24 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../cub3d.h"
#include "build_image.h"
#include "../raycasting_engine/raycasting_engine.h"
#include "mlx.h"

static void		draw_column_in_img(t_img *img, t_data *data, t_column *column)
{
	int		i;
	int		line;
	int		px;

	i = 0;
	while (i < data->mlx.mlx_height)
	{
		px = i * data->mlx.mlx_width + column->column;
		if (!get_sprite_color(data, column, i, &img->data[px]))
		{
			if (i < column->start)
				img->data[px] = get_sky_color(data);
			else if (i > column->end)
				img->data[px] = get_floor_color(data);
			else
			{
				if (column->height > data->mlx.mlx_height)
					line = i + (column->height - data->mlx.mlx_height) / 2;
				else
					line = i - column->start;
				img->data[px] = get_wall_color(data, column, line);
			}
		}
		i++;
	}
}

static void		draw_columns_in_img(t_img *img, t_column *columns, t_data *data)
{
	int		i;
	int		height;

	i = 0;
	while (i < data->mlx.mlx_width)
	{
		if (columns[i].height > data->mlx.mlx_height)
			height = data->mlx.mlx_height;
		else if (columns[i].height < 0)
			height = 0;
		else
			height = columns[i].height;
		columns[i].start = (data->mlx.mlx_height - height) / 2;
		columns[i].end = columns[i].start + height - 1;
		draw_column_in_img(img, data, &(columns[i]));
		i++;
	}
}

static void		build_columns(t_data *data, t_column *columns)
{
	double	offset;
	t_ray	ray;
	double	ray_angle;
	int		i;

	offset = -30;
	i = 0;
	while (i < data->mlx.mlx_width)
	{
		ray_angle = data->player.orientation + offset;
		ray_angle = (ray_angle > 360) ? ray_angle - 360 : ray_angle;
		ray_angle = (ray_angle < 0) ? ray_angle + 360 : ray_angle;
		ray.sprites = NULL;
		ray = get_ray(data, ray_angle, offset);
		offset += 60.0 / (float)(data->mlx.mlx_width - 1);
		columns[i].impact_x = ray.impact_x;
		columns[i].impact_y = ray.impact_y;
		columns[i].column = i;
		columns[i].height = data->mlx.mlx_width / ray.ray_len;
		columns[i].wall_orientation = ray.wall_orientation;
		columns[i].sprites = ray.sprites;
		i++;
	}
}

void			clear_columns(t_data *data, t_column *columns)
{
	int		i;

	i = 0;
	while (i < data->mlx.mlx_width)
	{
		ft_lstclear(&(columns[i].sprites), free);
		i++;
	}
	free(columns);
}

int				build_image(t_data *data, t_img **img)
{
	t_column	*columns;

	if (!(*img = malloc(sizeof(t_img))))
		return (ERR_MALLOC);
	(*img)->img = mlx_new_image(data->mlx.mlx_id, data->mlx.mlx_width,
			data->mlx.mlx_height);
	(*img)->data = (int *)mlx_get_data_addr(
			(*img)->img, &(*img)->bpp, &(*img)->size, &(*img)->endian);
	if (!(columns = malloc(sizeof(t_column) * data->mlx.mlx_width)))
		return (ERR_MALLOC);
	build_columns(data, columns);
	draw_columns_in_img(*img, columns, data);
	clear_columns(data, columns);
	return (OK);
}
