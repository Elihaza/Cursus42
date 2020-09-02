/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_engine_y.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:45:03 by ellarbi           #+#    #+#             */
/*   Updated: 2020/07/16 16:17:02 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_engine.h"
#include "../cub3d.h"
#include <math.h>

t_ray	get_y_first_quarter_ray_len(t_data *data, t_angle *angle)
{
	t_ray	ray;

	ray.sprites = NULL;
	ray.impact_x = data->player.pos_x +
		(data->player.pos_y - (int)data->player.pos_y) / tan(angle->rad_rel);
	ray.impact_y = (int)data->player.pos_y;
	ray.ray_len = (data->player.pos_y - ray.impact_y) / sin(angle->rad_rel);
	while (ray.impact_x >= 0 && ray.impact_x < data->map_width &&
		ray.impact_y >= 1 && ray.impact_y < data->map_height &&
		data->map[(int)(ray.impact_y - 1)][(int)ray.impact_x] != '1')
	{
		if (data->map[(int)(ray.impact_y - 1)][(int)ray.impact_x] == '2')
			handle_sprite_detection(&ray, data, angle, 'y');
		ray.impact_x += 1.0 / tan(angle->rad_rel);
		ray.impact_y -= 1;
		ray.ray_len = (data->player.pos_y - ray.impact_y) / sin(angle->rad_rel);
	}
	return (ray);
}

t_ray	get_y_second_quarter_ray_len(t_data *data, t_angle *angle)
{
	t_ray	ray;

	ray.sprites = NULL;
	ray.impact_x = data->player.pos_x +
		(ceil(data->player.pos_y) - data->player.pos_y) / tan(angle->rad_rel);
	ray.impact_y = ceil(data->player.pos_y);
	ray.ray_len = (ray.impact_y - data->player.pos_y) / sin(angle->rad_rel);
	while (ray.impact_x >= 0 && ray.impact_x < data->map_width &&
		ray.impact_y >= 0 && ray.impact_y < data->map_height &&
		data->map[(int)ray.impact_y][(int)ray.impact_x] != '1')
	{
		if (data->map[(int)ray.impact_y][(int)ray.impact_x] == '2')
			handle_sprite_detection(&ray, data, angle, 'y');
		ray.impact_x += 1.0 / tan(angle->rad_rel);
		ray.impact_y += 1;
		ray.ray_len = (ray.impact_y - data->player.pos_y) / sin(angle->rad_rel);
	}
	return (ray);
}

t_ray	get_y_third_quarter_ray_len(t_data *data, t_angle *angle)
{
	t_ray	ray;

	ray.sprites = NULL;
	ray.impact_x = data->player.pos_x -
		(ceil(data->player.pos_y) - data->player.pos_y) / tan(angle->rad_rel);
	ray.impact_y = ceil(data->player.pos_y);
	ray.ray_len = (ray.impact_y - data->player.pos_y) / sin(angle->rad_rel);
	while (ray.impact_x >= 0 && ray.impact_x < data->map_width &&
		ray.impact_y >= 0 && ray.impact_y < data->map_height &&
		data->map[(int)ray.impact_y][(int)ray.impact_x] != '1')
	{
		if (data->map[(int)ray.impact_y][(int)ray.impact_x] == '2')
			handle_sprite_detection(&ray, data, angle, 'y');
		ray.impact_x -= 1.0 / tan(angle->rad_rel);
		ray.impact_y += 1;
		ray.ray_len = (ray.impact_y - data->player.pos_y) / sin(angle->rad_rel);
	}
	return (ray);
}

t_ray	get_y_last_quarter_ray_len(t_data *data, t_angle *angle)
{
	t_ray	ray;

	ray.sprites = NULL;
	ray.impact_x = data->player.pos_x -
		(data->player.pos_y - (int)data->player.pos_y) / tan(angle->rad_rel);
	ray.impact_y = (int)data->player.pos_y;
	ray.ray_len = (data->player.pos_y - ray.impact_y) / sin(angle->rad_rel);
	while (ray.impact_x >= 0 && ray.impact_x < data->map_width &&
		ray.impact_y >= 1 && ray.impact_y < data->map_height &&
		data->map[(int)(ray.impact_y - 1)][(int)ray.impact_x] != '1')
	{
		if (data->map[(int)(ray.impact_y - 1)][(int)ray.impact_x] == '2')
			handle_sprite_detection(&ray, data, angle, 'y');
		ray.impact_x -= 1.0 / tan(angle->rad_rel);
		ray.impact_y -= 1;
		ray.ray_len = (data->player.pos_y - ray.impact_y) / sin(angle->rad_rel);
	}
	return (ray);
}
