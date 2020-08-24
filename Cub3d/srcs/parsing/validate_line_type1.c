/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line_type1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:41:02 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:41:03 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		validate_line_type1(char *map_line, int len)
{
	int i;

	i = 0;
	while (map_line[i] == '1')
		i++;
	if (i != len)
		return (0);
	return (1);
}
