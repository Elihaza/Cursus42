/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 12:44:02 by frdescam          #+#    #+#             */
/*   Updated: 2020/07/16 15:24:34 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../keys.h"
#include "../cub3d.h"
#include "../player_moves/move_player.h"
#include "draw_mlx.h"
#include "../exit_program/exit_program.h"
#include "libft.h"

static int	is_key_pressed(t_data *data)
{
	if (data->keylist[MLX_KEY_E] || data->keylist[MLX_KEY_Q] ||
			data->keylist[MLX_KEY_RIGHT] || data->keylist[MLX_KEY_LEFT] ||
			data->keylist[MLX_KEY_W] || data->keylist[MLX_KEY_UP] ||
			data->keylist[MLX_KEY_S] || data->keylist[MLX_KEY_DOWN] ||
			data->keylist[MLX_KEY_D] || data->keylist[MLX_KEY_A] ||
			data->keylist[MLX_KEY_ESC])
		return (ERR);
	return (OK);
}

int			handle_moves(t_data *data)
{
	if (is_key_pressed(data))
	{
		if (data->keylist[MLX_KEY_ESC])
			exit(0);
		if (data->keylist[MLX_KEY_RIGHT] || data->keylist[MLX_KEY_E])
			data->player.orientation += 2;
		if (data->keylist[MLX_KEY_LEFT] || data->keylist[MLX_KEY_Q])
			data->player.orientation -= 2;
		if (data->keylist[MLX_KEY_W] || data->keylist[MLX_KEY_UP])
			move_player_up(data);
		if (data->keylist[MLX_KEY_S] || data->keylist[MLX_KEY_DOWN])
			move_player_down(data);
		if (data->keylist[MLX_KEY_D])
			move_player_right(data);
		if (data->keylist[MLX_KEY_A])
			move_player_left(data);
		if (data->player.orientation > 360)
			data->player.orientation -= 360;
		if (data->player.orientation < 0)
			data->player.orientation += 360;
		draw_image_mlx(data);
	}
	return (OK);
}

void		convert_keycode(int *keycode)
{
	if (*keycode == X11_KEY_UP)
		*keycode = MLX_KEY_UP;
	else if (*keycode == X11_KEY_DOWN)
		*keycode = MLX_KEY_DOWN;
	else if (*keycode == X11_KEY_RIGHT)
		*keycode = MLX_KEY_RIGHT;
	else if (*keycode == X11_KEY_LEFT)
		*keycode = MLX_KEY_LEFT;
	else if (*keycode == X11_KEY_W)
		*keycode = MLX_KEY_W;
	else if (*keycode == X11_KEY_A)
		*keycode = MLX_KEY_A;
	else if (*keycode == X11_KEY_S)
		*keycode = MLX_KEY_S;
	else if (*keycode == X11_KEY_D)
		*keycode = MLX_KEY_D;
}

int			handle_keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
		exit_program(data);
	if (LINUX)
		convert_keycode(&keycode);
	if (keycode < 280)
		data->keylist[keycode] = 1;
	return (OK);
}

int			handle_keyrelease(int keycode, t_data *data)
{
	if (LINUX)
		convert_keycode(&keycode);
	if (keycode < 280)
		data->keylist[keycode] = 0;
	return (OK);
}
