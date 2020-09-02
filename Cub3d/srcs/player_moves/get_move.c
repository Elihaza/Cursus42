/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:29:58 by frdescam          #+#    #+#             */
/*   Updated: 2020/07/20 08:49:09 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "move_player.h"

static	void	get_first_quarter_move(t_move *move, int angle)
{
	double	rad_angle;

	rad_angle = angle * M_PI / 180;
	move->x_shift = sin(rad_angle) * 0.2;
	move->y_shift = cos(rad_angle) * 0.2 * -1;
	move->offset_wall_x = 0.5;
	move->offset_wall_y = -0.5;
}

static	void	get_second_quarter_move(t_move *move, int angle)
{
	double	rad_angle;

	rad_angle = (180 - angle) * M_PI / 180;
	move->x_shift = sin(rad_angle) * 0.2;
	move->y_shift = cos(rad_angle) * 0.2;
	move->offset_wall_x = 0.5;
	move->offset_wall_y = 0.5;
}

static	void	get_third_quarter_move(t_move *move, int angle)
{
	double	rad_angle;

	rad_angle = (angle - 180) * M_PI / 180;
	move->x_shift = sin(rad_angle) * 0.2 * -1;
	move->y_shift = cos(rad_angle) * 0.2;
	move->offset_wall_x = -0.5;
	move->offset_wall_y = 0.5;
}

static	void	get_last_quarter_move(t_move *move, int angle)
{
	double	rad_angle;

	rad_angle = (360 - angle) * M_PI / 180;
	move->x_shift = sin(rad_angle) * 0.2 * -1;
	move->y_shift = cos(rad_angle) * 0.2 * -1;
	move->offset_wall_x = -0.5;
	move->offset_wall_y = -0.5;
}

t_move			get_move(int angle)
{
	t_move	move;

	if (angle >= 0 && angle < 90)
		get_first_quarter_move(&move, angle);
	else if (angle >= 90 && angle < 180)
		get_second_quarter_move(&move, angle);
	else if (angle >= 180 && angle < 270)
		get_third_quarter_move(&move, angle);
	else
		get_last_quarter_move(&move, angle);
	return (move);
}
