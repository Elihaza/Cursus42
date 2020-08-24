/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:39:58 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:40:03 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	validate_map(t_parameters *params)
{
	int h;

	if (validate_line_type1((params->map)[0], params->map_w) == 0)
		return (0);
	h = 1;
	while (h < params->map_h && params->map && (params->map)[h])
	{
		if (validate_line_type2((params->map)[h], h, params) == 0)
			return (0);
		h++;
	}
	if (params->posx == 0)
		return (0);
	if (validate_line_type1((params->map)[h - 1], params->map_w) == 0)
		return (0);
	return (1);
}
