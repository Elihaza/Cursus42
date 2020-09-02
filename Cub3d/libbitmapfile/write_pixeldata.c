/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pixeldata.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:06:50 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/18 14:11:15 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmapfile.h"

int		write_pixeldata(int fd, t_bitmapinfoheader bih, int **img)
{
	int				x;
	int				y;
	int				i;
	unsigned char	*buf;

	bih.img_size.i = (bih.img_width.i * bih.img_height.i) * 4;
	if (!(buf = malloc(sizeof(unsigned char) * (bih.img_size.i + 1))))
		return (-1);
	x = bih.img_height.i;
	i = 0;
	while (--x >= 0 && (y = -1))
	{
		while (++y < bih.img_width.i)
		{
			bih.totalcolors.i = img[x][y];
			buf[i] = bih.totalcolors.d[0];
			buf[i + 1] = bih.totalcolors.d[1];
			buf[i + 2] = bih.totalcolors.d[2];
			buf[i + 3] = bih.totalcolors.d[3];
			i += 4;
		}
	}
	write(fd, buf, bih.img_size.i);
	free(buf);
	return (0);
}
