/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 21:05:33 by ellarbi           #+#    #+#             */
/*   Updated: 2020/07/23 16:27:25 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "../cub3d.h"
#include "handle_events.h"
#include "draw_mlx.h"
#include "../init/init.h"
#include "../errors/errors.h"
#include "bmp/bmp.h"
#include "../exit_program/exit_program.h"

int		main(int argc, char **argv)
{
	int		ret_code;
	t_data	*data;

	if ((ret_code = init(argc, argv, &data)) != OK)
		handle_errors(ret_code, data);
	if (argc == 3)
	{
		if ((ret_code = save_bmp(data)))
			handle_errors(ret_code, data);
		exit_program(data);
	}
	else
	{
		if (!(data->mlx.mlx_window_id = mlx_new_window(data->mlx.mlx_id,
						data->mlx.mlx_width, data->mlx.mlx_height, "Cub3D")))
			handle_errors(ret_code, data);
		mlx_mouse_hide(data->mlx.mlx_id, data->mlx.mlx_window_id);
		mlx_hook(data->mlx.mlx_window_id, 2, 1L << 0, handle_keypress, data);
		mlx_hook(data->mlx.mlx_window_id, 3, 1L << 1, handle_keyrelease, data);
		mlx_hook(data->mlx.mlx_window_id, 17, 1L << 17, exit_program, data);
		draw_image_mlx(data);
		mlx_loop_hook(data->mlx.mlx_id, handle_moves, data);
		mlx_loop(data->mlx.mlx_id);
	}
}
