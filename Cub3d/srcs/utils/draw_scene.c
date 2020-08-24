/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:22:00 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:26:27 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	**draw_scene(t_parameters p)
{
	t_dda_parameters	dda;
	int					**buffer;
	int					x;
	double				*zbuffer;

	if (!(buffer = (int**)new_tda(sizeof(int), p.win_h, p.win_w)))
		return (NULL);
	if (!(zbuffer = (double*)malloc(sizeof(double) * p.win_w)))
		return (NULL);
	x = 0;
	while (x < p.win_w)
	{
		dda_init(p, &dda, x);
		dda_perform(&dda, p.map);
		dda_data(&dda, p, &zbuffer[x]);
		draw_textured_stripe(buffer, x, dda, p);
		x++;
	}
	draw_sprites(buffer, p, zbuffer);
	free(zbuffer);
	return (buffer);
}
