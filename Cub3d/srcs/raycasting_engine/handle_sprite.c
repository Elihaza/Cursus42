/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:48:06 by ellarbi           #+#    #+#             */
/*   Updated: 2020/07/25 13:16:00 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_engine.h"
#include "libft.h"
#include "../cub3d.h"
#include <math.h>

void	handle_sprite_detection2(t_ray *ray, t_data *data, t_angle *angle_ray,
		t_sprite *new_sprite)
{
	if (is_same_x_top(new_sprite, data, ray))
	{
		if (new_sprite->pos_x <= data->player.pos_x &&
		ray->impact_x >= data->player.pos_x &&
		new_sprite->pos_y < data->player.pos_y)
		{
			new_sprite->angle_sprite_ray = new_sprite->angle_sprite +
				angle_ray->rad_rel;
			new_sprite->texture_column =
				0.5 - new_sprite->distance_from_player *
				tan(new_sprite->angle_sprite_ray);
		}
		else
		{
			new_sprite->angle_sprite_ray = new_sprite->angle_sprite +
				angle_ray->rad_rel;
			new_sprite->texture_column =
				0.5 + new_sprite->distance_from_player *
				tan(new_sprite->angle_sprite_ray);
		}
	}
	else
		handle_sprite_detection3(ray, data, angle_ray, new_sprite);
}

void	build_sprite(t_data *data, t_sprite **new_sprite,
		t_angle *angle_ray, t_ray *ray)
{
	double		x_diff;
	double		y_diff;

	x_diff = fabs(data->player.pos_x - (*new_sprite)->pos_x);
	y_diff = fabs(data->player.pos_y - (*new_sprite)->pos_y);
	(*new_sprite)->angle_sprite = atan(y_diff / x_diff);
	(*new_sprite)->angle_sprite_ray =
		fabs((*new_sprite)->angle_sprite - angle_ray->rad_rel);
	if (y_diff < 1)
		(*new_sprite)->distance_from_player =
			x_diff / cos((*new_sprite)->angle_sprite);
	else
		(*new_sprite)->distance_from_player =
			y_diff / sin((*new_sprite)->angle_sprite);
	(*new_sprite)->impact_distance = ray->ray_len;
}

void	handle_sprite_detection(t_ray *ray, t_data *data, t_angle *angle_ray,
		char ray_type)
{
	t_list		*new_elem;
	t_sprite	*new_sprite;

	new_sprite = malloc(sizeof(t_sprite));
	if (ray_type == 'x' && angle_ray->deg_abs > 180)
		new_sprite->pos_x = ((int)ray->impact_x) - 0.5;
	else
		new_sprite->pos_x = ((int)ray->impact_x) + 0.5;
	if (ray_type == 'y' && (angle_ray->deg_abs < 90 ||
		angle_ray->deg_abs > 270))
		new_sprite->pos_y = ((int)ray->impact_y) - 0.5;
	else
		new_sprite->pos_y = ((int)ray->impact_y) + 0.5;
	build_sprite(data, &new_sprite, angle_ray, ray);
	handle_sprite_detection2(ray, data, angle_ray, new_sprite);
	new_elem = ft_lstnew("", new_sprite);
	ft_lstadd_front(&(ray->sprites), new_elem);
}
