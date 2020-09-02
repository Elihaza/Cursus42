/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:47:43 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/23 12:38:09 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_parameters params;

	initialize_cub3d(&params, av[1]);
	if (ac > 2 && ft_strcmp(av[2], "-save") == 0)
	{
		save_scene(&params);
		quit_program(&params, NULL);
	}
	initialize_mlx_window(&params);
	display_scene(params);
	mlx_hook(params.win_id, 2, 0, &key_hook, &params);
	mlx_hook(params.win_id, 17, 0, &close_button, &params);
	mlx_loop(params.mlx_id);
}
