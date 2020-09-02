/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 16:30:20 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/25 15:19:55 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	ft_puterror(char const *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(2, "Error\n", 6);
	write(2, s, i);
}

void		quit_program(t_parameters *params, const char *error_msg)
{
	if (params->img_id)
		mlx_destroy_image(params->mlx_id, params->img_id);
	if (params->north_texture.id)
		mlx_destroy_image(params->mlx_id, params->north_texture.id);
	if (params->south_texture.id)
		mlx_destroy_image(params->mlx_id, params->south_texture.id);
	if (params->west_texture.id)
		mlx_destroy_image(params->mlx_id, params->west_texture.id);
	if (params->east_texture.id)
		mlx_destroy_image(params->mlx_id, params->east_texture.id);
	if (params->sprite_texture.id)
		mlx_destroy_image(params->mlx_id, params->sprite_texture.id);
	if (params->win_id)
		mlx_destroy_window(params->mlx_id, params->win_id);
	if (params->map)
		free_tda((void**)params->map, params->map_h);
	if (params->sprites)
		free(params->sprites);
	if (error_msg)
		ft_puterror(error_msg);
	exit(1);
}
