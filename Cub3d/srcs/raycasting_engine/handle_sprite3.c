/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sprite3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:15:12 by frdescam          #+#    #+#             */
/*   Updated: 2020/07/25 13:21:17 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_engine.h"
#include <math.h>

void	handle_sprite_detection7(t_angle *angle_ray, t_sprite *new_sprite)
{
	if (angle_ray->deg_abs < 270)
	{
		if (angle_ray->rad_rel < new_sprite->angle_sprite)
			new_sprite->texture_column =
				0.5 + new_sprite->distance_from_player *
				tan(new_sprite->angle_sprite_ray);
		else
			new_sprite->texture_column =
				0.5 - new_sprite->distance_from_player *
				tan(new_sprite->angle_sprite_ray);
	}
	else
	{
		if (angle_ray->rad_rel > new_sprite->angle_sprite)
			new_sprite->texture_column =
				0.5 + new_sprite->distance_from_player *
				tan(new_sprite->angle_sprite_ray);
		else
			new_sprite->texture_column =
				0.5 - new_sprite->distance_from_player *
				tan(new_sprite->angle_sprite_ray);
	}
}

void	handle_sprite_detection6(t_angle *angle_ray, t_sprite *new_sprite)
{
	if (angle_ray->deg_abs < 90)
	{
		if (angle_ray->rad_rel < new_sprite->angle_sprite)
			new_sprite->texture_column =
				0.5 + new_sprite->distance_from_player *
				tan(new_sprite->angle_sprite_ray);
		else
			new_sprite->texture_column =
				0.5 - new_sprite->distance_from_player *
				tan(new_sprite->angle_sprite_ray);
	}
	else if (angle_ray->deg_abs < 180)
	{
		if (angle_ray->rad_rel > new_sprite->angle_sprite)
			new_sprite->texture_column =
				0.5 + new_sprite->distance_from_player *
				tan(new_sprite->angle_sprite_ray);
		else
			new_sprite->texture_column =
				0.5 - new_sprite->distance_from_player *
				tan(new_sprite->angle_sprite_ray);
	}
	else
		handle_sprite_detection7(angle_ray, new_sprite);
}

void	handle_sprite_detection5(t_ray *ray, t_data *data, t_angle *angle_ray,
		t_sprite *new_sprite)
{
	if (is_same_y_right(new_sprite, data, ray))
	{
		if (new_sprite->pos_y <= data->player.pos_y &&
		ray->impact_y >= data->player.pos_y &&
		new_sprite->pos_x > data->player.pos_x)
		{
			new_sprite->angle_sprite_ray = new_sprite->angle_sprite +
				angle_ray->rad_rel;
			new_sprite->texture_column =
				0.5 + new_sprite->distance_from_player *
				tan(new_sprite->angle_sprite_ray);
		}
		else
		{
			new_sprite->angle_sprite_ray = new_sprite->angle_sprite +
				angle_ray->rad_rel;
			new_sprite->texture_column =
				0.5 - new_sprite->distance_from_player *
				tan(new_sprite->angle_sprite_ray);
		}
	}
	else
		handle_sprite_detection6(angle_ray, new_sprite);
}

void	handle_sprite_detection4(t_ray *ray, t_data *data, t_angle *angle_ray,
		t_sprite *new_sprite)
{
	if (is_same_y_left(new_sprite, data, ray))
	{
		if (new_sprite->pos_y <= data->player.pos_y &&
		ray->impact_y >= data->player.pos_y &&
		new_sprite->pos_x < data->player.pos_x)
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
		handle_sprite_detection5(ray, data, angle_ray, new_sprite);
}

void	handle_sprite_detection3(t_ray *ray, t_data *data, t_angle *angle_ray,
		t_sprite *new_sprite)
{
	if (is_same_x_bottom(new_sprite, data, ray))
	{
		if (new_sprite->pos_x <= data->player.pos_x &&
		ray->impact_x >= data->player.pos_x &&
		new_sprite->pos_y > data->player.pos_y)
		{
			new_sprite->angle_sprite_ray = new_sprite->angle_sprite +
				angle_ray->rad_rel;
			new_sprite->texture_column =
				0.5 + new_sprite->distance_from_player *
				tan(new_sprite->angle_sprite_ray);
		}
		else
		{
			new_sprite->angle_sprite_ray = new_sprite->angle_sprite +
				angle_ray->rad_rel;
			new_sprite->texture_column =
				0.5 - new_sprite->distance_from_player *
				tan(new_sprite->angle_sprite_ray);
		}
	}
	else
		handle_sprite_detection4(ray, data, angle_ray, new_sprite);
}
