/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line_type2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:41:13 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:42:26 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		validate_line_type2(char *map_line, int l, t_parameters *params)
{
	int i;
	int c;

	i = 0;
	while ((c = ft_index("012NSEW", map_line[i])) > -1)
	{
		if (c > 2)
			set_player_position(params, c, l, i);
		i++;
	}
	if (i != params->map_w)
		return (0);
	if (map_line[0] != '1' || map_line[i - 1] != '1')
		return (0);
	return (1);
}
