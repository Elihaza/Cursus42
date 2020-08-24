/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:14:53 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:14:55 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	key_hook(int keycode, void *params)
{
	t_parameters *p;

	p = params;
	if (keycode == K_W)
		move_forward(p);
	if (keycode == K_S)
		move_backward(p);
	if (keycode == K_A)
		move_left(p);
	if (keycode == K_D)
		move_right(p);
	if (keycode == DK_LEFT)
		camera_left(p);
	if (keycode == DK_RIGHT)
		camera_right(p);
	if (keycode == K_ESC)
		quit_program(params, NULL);
	display_scene(*p);
	return (0);
}
