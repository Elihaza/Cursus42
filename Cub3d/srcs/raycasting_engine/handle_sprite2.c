/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_sprite2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:13:50 by frdescam          #+#    #+#             */
/*   Updated: 2020/07/25 13:16:01 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_engine.h"

int		is_same_x_top(t_sprite *new_sprite, t_data *data, t_ray *ray)
{
	if ((new_sprite->pos_x <= data->player.pos_x &&
		ray->impact_x >= data->player.pos_x &&
		new_sprite->pos_y < data->player.pos_y) ||
		(new_sprite->pos_x >= data->player.pos_x &&
		ray->impact_x <= data->player.pos_x &&
		new_sprite->pos_y < data->player.pos_y))
		return (1);
	return (0);
}

int		is_same_x_bottom(t_sprite *new_sprite, t_data *data, t_ray *ray)
{
	if ((new_sprite->pos_x <= data->player.pos_x &&
		ray->impact_x >= data->player.pos_x &&
		new_sprite->pos_y > data->player.pos_y) ||
		(new_sprite->pos_x >= data->player.pos_x &&
		ray->impact_x <= data->player.pos_x &&
		new_sprite->pos_y > data->player.pos_y))
		return (1);
	return (0);
}

int		is_same_y_left(t_sprite *new_sprite, t_data *data, t_ray *ray)
{
	if ((new_sprite->pos_y <= data->player.pos_y &&
		ray->impact_y >= data->player.pos_y &&
		new_sprite->pos_x < data->player.pos_x) ||
		(new_sprite->pos_y >= data->player.pos_y &&
		ray->impact_y <= data->player.pos_y &&
		new_sprite->pos_x < data->player.pos_x))
		return (1);
	return (0);
}

int		is_same_y_right(t_sprite *new_sprite, t_data *data, t_ray *ray)
{
	if ((new_sprite->pos_y <= data->player.pos_y &&
		ray->impact_y >= data->player.pos_y &&
		new_sprite->pos_x > data->player.pos_x) ||
		(new_sprite->pos_y >= data->player.pos_y &&
		ray->impact_y <= data->player.pos_y &&
		new_sprite->pos_x > data->player.pos_x))
		return (1);
	return (0);
}
