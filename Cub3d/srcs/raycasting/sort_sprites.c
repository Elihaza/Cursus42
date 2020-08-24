/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:12:46 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:38:44 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_sprites(t_sprite *sprites, int array_size)
{
	int			i;
	t_sprite	tmp;

	i = 0;
	while (i < array_size - 1)
	{
		if (sprites[i].distance < sprites[i + 1].distance)
		{
			tmp = sprites[i];
			sprites[i] = sprites[i + 1];
			sprites[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
