/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:25:28 by ellarbi           #+#    #+#             */
/*   Updated: 2020/07/20 08:56:28 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../cub3d.h"
#include "move_player.h"

static	int	is_move_possible(t_player *player, char **map, double y_shift,
		double x_shift)
{
	double	new_pos_y;
	double	new_pos_x;

	if (y_shift)
	{
		new_pos_y = player->pos_y + y_shift;
		if (map[(int)(new_pos_y + 0.2)][(int)(player->pos_x + 0.2)] != '0' ||
			map[(int)(new_pos_y - 0.2)][(int)(player->pos_x + 0.2)] != '0' ||
			map[(int)(new_pos_y + 0.2)][(int)(player->pos_x - 0.2)] != '0' ||
			map[(int)(new_pos_y - 0.2)][(int)(player->pos_x - 0.2)] != '0')
			return (0);
	}
	if (x_shift)
	{
		new_pos_x = player->pos_x + x_shift;
		if (map[(int)(player->pos_y + 0.2)][(int)(new_pos_x + 0.2)] != '0' ||
			map[(int)(player->pos_y - 0.2)][(int)(new_pos_x + 0.2)] != '0' ||
			map[(int)(player->pos_y + 0.2)][(int)(new_pos_x - 0.2)] != '0' ||
			map[(int)(player->pos_y - 0.2)][(int)(new_pos_x - 0.2)] != '0')
			return (0);
	}
	return (1);
}

void		move_player_up(t_data *data)
{
	int		angle;
	t_move	move;

	angle = data->player.orientation;
	move = get_move(angle);
	if (is_move_possible(&data->player, data->map, 0, move.x_shift))
		data->player.pos_x += move.x_shift;
	if (is_move_possible(&data->player, data->map, move.y_shift, 0))
		data->player.pos_y += move.y_shift;
}

void		move_player_down(t_data *data)
{
	int		angle;
	t_move	move;

	if (data->player.orientation > 180)
		angle = data->player.orientation - 180;
	else
		angle = data->player.orientation + 180;
	move = get_move(angle);
	if (is_move_possible(&data->player, data->map, 0, move.x_shift))
		data->player.pos_x += move.x_shift;
	if (is_move_possible(&data->player, data->map, move.y_shift, 0))
		data->player.pos_y += move.y_shift;
}

void		move_player_right(t_data *data)
{
	int		angle;
	t_move	move;

	if (data->player.orientation > 270)
		angle = data->player.orientation - 270;
	else
		angle = data->player.orientation + 90;
	move = get_move(angle);
	if (is_move_possible(&data->player, data->map, 0, move.x_shift))
		data->player.pos_x += move.x_shift;
	if (is_move_possible(&data->player, data->map, move.y_shift, 0))
		data->player.pos_y += move.y_shift;
}

void		move_player_left(t_data *data)
{
	int		angle;
	t_move	move;

	if (data->player.orientation > 90)
		angle = data->player.orientation - 90;
	else
		angle = data->player.orientation + 270;
	move = get_move(angle);
	if (is_move_possible(&data->player, data->map, 0, move.x_shift))
		data->player.pos_x += move.x_shift;
	if (is_move_possible(&data->player, data->map, move.y_shift, 0))
		data->player.pos_y += move.y_shift;
}
