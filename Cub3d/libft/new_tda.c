/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:37:32 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/18 13:42:38 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**new_tda(int size, int height, int width)
{
	void	**two_dimensional_array;
	int		x;

	if (!(two_dimensional_array = (void**)malloc(sizeof(void*) * height)))
		return (NULL);
	x = -1;
	while (++x < height)
	{
		if (!(two_dimensional_array[x] = malloc(size * width)))
		{
			free_tda(two_dimensional_array, x);
			return (NULL);
		}
		ft_bzero(two_dimensional_array[x], size * width);
	}
	return (two_dimensional_array);
}
