/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 18:12:47 by ellarbi           #+#    #+#             */
/*   Updated: 2020/07/16 14:47:36 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "mlx.h"
#include "build_image.h"

int				draw_image_mlx(t_data *data)
{
	t_img	*img;
	int		ret_code;

	if ((ret_code = build_image(data, &img)) != OK)
		return (ret_code);
	mlx_put_image_to_window(
			data->mlx.mlx_id, data->mlx.mlx_window_id, img->img, 0, 0);
	mlx_destroy_image(data->mlx.mlx_id, img->img);
	free(img);
	return (0);
}
