/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:40:25 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/22 17:15:51 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_params(t_parameters *params, const char *line)
{
	if (line[0] == 'R' && line[1] == ' ')
		set_resolution(params, &line[2]);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		set_texture(params, &(params->north_texture), &line[2]);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		set_texture(params, &(params->south_texture), &line[2]);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		set_texture(params, &(params->west_texture), &line[2]);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		set_texture(params, &(params->east_texture), &line[2]);
	else if (line[0] == 'S' && line[1] == ' ')
		set_texture(params, &(params->sprite_texture), &line[2]);
	else if (line[0] == 'F' && line[1] == ' ')
		set_floor_color(params, &line[2]);
	else if (line[0] == 'C' && line[1] == ' ')
		set_ceiling_color(params, &line[2]);
	else
		quit_program(params, "Unknown configuration identifier.");
}
