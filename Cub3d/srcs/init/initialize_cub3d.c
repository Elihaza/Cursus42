/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_cub3d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:18:54 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/22 16:37:47 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	initialize_cub3d(t_parameters *params, const char *arg1)
{
	set_params_to_default(params);
	params->mlx_id = mlx_init();
	if (!params->mlx_id)
		quit_program(params, "Minilibx initilization failed.");
	init_params(params, arg1);
}
