/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:12:30 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/23 12:50:19 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_scene(t_parameters params)
{
	int **buf;

	buf = draw_scene(params);
	buffer_to_image(params.win_h, params.win_w, buf, &params.img);
	free_tda((void**)buf, params.win_h);
	mlx_put_image_to_window(params.mlx_id, params.win_id, params.img_id, 0, 0);
}
