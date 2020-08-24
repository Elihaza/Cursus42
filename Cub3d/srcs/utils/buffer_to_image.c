/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_to_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:21:53 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:23:09 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	buffer_to_image(int h, int w, int **buf, void **img)
{
	unsigned char	*c;
	int				i;
	int				a;
	int				b;

	c = *img;
	a = 0;
	i = 0;
	while (a < h)
	{
		b = 0;
		while (b < w)
		{
			c[i + 2] = buf[a][b] / 65536;
			c[i + 1] = (buf[a][b] / 256) % 256;
			c[i] = buf[a][b] % 256;
			b++;
			i += 4;
		}
		a++;
	}
}
