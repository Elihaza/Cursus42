/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:12:08 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:12:13 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	save_scene(t_parameters *params)
{
	int **buf;
	int i;

	buf = draw_scene(*params);
	i = create_bmpfile("screenshot.bmp", params->win_w, params->win_h, buf);
	free_tda((void**)buf, params->win_h);
	if (i == -1)
		quit_program(params, "Couldn't create .bmp file.");
}
