/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_engine.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 19:17:34 by frdescam          #+#    #+#             */
/*   Updated: 2020/07/22 17:28:22 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_engine.h"
#include "../cub3d.h"
#include <math.h>
#include <stdio.h>

typedef struct s_ray	t_ray;

static void		get_f_arr(t_ray (*f[2])(t_data *data, t_angle *angle),
		double angle)
{
	if (angle >= 0 && angle < 90)
	{
		f[0] = get_x_first_quarter_ray_len;
		f[1] = get_y_first_quarter_ray_len;
	}
	else if (angle >= 90 && angle < 180)
	{
		f[0] = get_x_second_quarter_ray_len;
		f[1] = get_y_second_quarter_ray_len;
	}
	else if (angle >= 180 && angle < 270)
	{
		f[0] = get_x_third_quarter_ray_len;
		f[1] = get_y_third_quarter_ray_len;
	}
	else
	{
		f[0] = get_x_last_quarter_ray_len;
		f[1] = get_y_last_quarter_ray_len;
	}
}

int				is_sprite_closer(void *content1, void *content2)
{
	t_sprite	*sprite1;
	t_sprite	*sprite2;

	sprite1 = content1;
	sprite2 = content2;
	if (sprite1->distance_from_player < sprite2->distance_from_player)
		return (1);
	return (0);
}

static void		remove_unwanted_sprites(t_ray *ray)
{
	t_list		*elem;
	t_list		*prev;
	t_sprite	*sprite;

	prev = NULL;
	elem = ray->sprites;
	while (elem)
	{
		sprite = elem->content;
		if (sprite->impact_distance > ray->ray_len
			|| sprite->texture_column > 1 || sprite->texture_column < 0)
			remove_sprite(prev, &elem, ray);
		else
		{
			prev = elem;
			elem = elem->next;
		}
	}
}

static t_ray	choose_ray(double offset, double angle, t_ray ray_x,
		t_ray ray_y)
{
	if (ray_y.ray_len < ray_x.ray_len)
	{
		if (angle >= 90 && angle < 270)
			ray_y.wall_orientation = 'S';
		else
			ray_y.wall_orientation = 'N';
		ft_lstcat(&ray_y.sprites, &ray_x.sprites);
		ft_lstsort(&ray_y.sprites, &is_sprite_closer);
		remove_unwanted_sprites(&ray_y);
		ray_y.ray_len *= cos(offset * M_PI / 180.0);
		return (ray_y);
	}
	else
	{
		if (angle >= 0 && angle < 180)
			ray_x.wall_orientation = 'E';
		else
			ray_x.wall_orientation = 'W';
		ft_lstcat(&ray_x.sprites, &ray_y.sprites);
		ft_lstsort(&ray_x.sprites, &is_sprite_closer);
		remove_unwanted_sprites(&ray_x);
		ray_x.ray_len *= cos(offset * M_PI / 180.0);
		return (ray_x);
	}
}

t_ray			get_ray(t_data *data, double angle_deg_abs, double offset)
{
	t_ray	(*get_ray_len[2])(t_data *data, t_angle *angle);
	t_ray	ray_y;
	t_ray	ray_x;
	t_angle	angle;

	set_angle(&angle, angle_deg_abs);
	get_f_arr(get_ray_len, angle_deg_abs);
	ray_x = get_ray_len[0](data, &angle);
	ray_y = get_ray_len[1](data, &angle);
	return (choose_ray(offset, angle_deg_abs, ray_x, ray_y));
}
