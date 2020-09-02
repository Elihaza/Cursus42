/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_engine_x.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:44:35 by frdescam          #+#    #+#             */
/*   Updated: 2020/07/16 16:19:48 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_engine.h"
#include "../cub3d.h"
#include <math.h>

t_ray	get_x_first_quarter_ray_len(t_data *data, t_angle *angle)
{
	t_ray	ray;

	ray.sprites = NULL;
	ray.impact_x = ceil(data->player.pos_x);
	ray.impact_y = data->player.pos_y - (tan(angle->rad_rel) *
			(ceil(data->player.pos_x) - data->player.pos_x));
	ray.ray_len = (ray.impact_x - data->player.pos_x) / cos(angle->rad_rel);
	while (ray.impact_x >= 0 && ray.impact_x < data->map_width &&
		ray.impact_y >= 0 && ray.impact_y < data->map_height &&
		data->map[(int)ray.impact_y][(int)ray.impact_x] != '1')
	{
		if (data->map[(int)ray.impact_y][(int)ray.impact_x] == '2')
			handle_sprite_detection(&ray, data, angle, 'x');
		ray.impact_x += 1;
		ray.impact_y = ray.impact_y - (tan(angle->rad_rel) * 1.0);
		ray.ray_len = (ray.impact_x - data->player.pos_x) / cos(angle->rad_rel);
	}
	return (ray);
}

t_ray	get_x_second_quarter_ray_len(t_data *data, t_angle *angle)
{
	t_ray	ray;

	ray.sprites = NULL;
	ray.impact_x = ceil(data->player.pos_x);
	ray.impact_y = data->player.pos_y + tan(angle->rad_rel) *
		(ceil(data->player.pos_x) - data->player.pos_x);
	ray.ray_len = (ray.impact_x - data->player.pos_x) / cos(angle->rad_rel);
	while (ray.impact_x >= 0 && ray.impact_x < data->map_width &&
		ray.impact_y >= 0 && ray.impact_y < data->map_height &&
		data->map[(int)ray.impact_y][(int)ray.impact_x] != '1')
	{
		if (data->map[(int)ray.impact_y][(int)ray.impact_x] == '2')
			handle_sprite_detection(&ray, data, angle, 'x');
		ray.impact_x += 1;
		ray.impact_y = ray.impact_y + (tan(angle->rad_rel) * 1.0);
		ray.ray_len = (ray.impact_x - data->player.pos_x) / cos(angle->rad_rel);
	}
	return (ray);
}

t_ray	get_x_third_quarter_ray_len(t_data *data, t_angle *angle)
{
	t_ray	ray;

	ray.sprites = NULL;
	ray.impact_x = (int)data->player.pos_x;
	ray.impact_y = data->player.pos_y + tan(angle->rad_rel) *
		(data->player.pos_x - (int)data->player.pos_x);
	ray.ray_len = (data->player.pos_x - ray.impact_x) / cos(angle->rad_rel);
	while (ray.impact_x >= 1 && ray.impact_x < data->map_width &&
		ray.impact_y >= 0 && ray.impact_y < data->map_height &&
		data->map[(int)ray.impact_y][(int)(ray.impact_x - 1)] != '1')
	{
		if (data->map[(int)ray.impact_y][(int)(ray.impact_x - 1)] == '2')
			handle_sprite_detection(&ray, data, angle, 'x');
		ray.impact_x -= 1;
		ray.impact_y = ray.impact_y + (tan(angle->rad_rel) * 1.0);
		ray.ray_len = (data->player.pos_x - ray.impact_x) / cos(angle->rad_rel);
	}
	return (ray);
}

t_ray	get_x_last_quarter_ray_len(t_data *data, t_angle *angle)
{
	t_ray	ray;

	ray.sprites = NULL;
	ray.impact_x = (int)data->player.pos_x;
	ray.impact_y = data->player.pos_y - tan(angle->rad_rel) *
		(data->player.pos_x - (int)data->player.pos_x);
	ray.ray_len = (data->player.pos_x - ray.impact_x) / cos(angle->rad_rel);
	while (ray.impact_x >= 1 && ray.impact_x < data->map_width &&
		ray.impact_y >= 0 && ray.impact_y < data->map_height &&
		data->map[(int)ray.impact_y][(int)(ray.impact_x - 1)] != '1')
	{
		if (data->map[(int)ray.impact_y][(int)(ray.impact_x - 1)] == '2')
			handle_sprite_detection(&ray, data, angle, 'x');
		ray.impact_x -= 1;
		ray.impact_y = ray.impact_y - (tan(angle->rad_rel) * 1.0);
		ray.ray_len = (data->player.pos_x - ray.impact_x) / cos(angle->rad_rel);
	}
	return (ray);
}
