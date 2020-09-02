/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bmpinfoheader.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:06:23 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/18 14:06:25 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmapfile.h"

void	write_bmpinfoheader(int fd, t_bitmapinfoheader bmpih)
{
	unsigned char buf[40];

	dint4cpy(bmpih.headersize, &buf[0]);
	dint4cpy(bmpih.img_width, &buf[4]);
	dint4cpy(bmpih.img_height, &buf[8]);
	buf[12] = bmpih.planes.d[0];
	buf[13] = bmpih.planes.d[1];
	buf[14] = bmpih.bpp.d[0];
	buf[15] = bmpih.bpp.d[1];
	dint4cpy(bmpih.compression, &buf[16]);
	dint4cpy(bmpih.img_size, &buf[20]);
	dint4cpy(bmpih.xpixelspermeter, &buf[24]);
	dint4cpy(bmpih.ypixelspermeter, &buf[28]);
	dint4cpy(bmpih.totalcolors, &buf[32]);
	dint4cpy(bmpih.importantcolors, &buf[36]);
	write(fd, buf, 40);
}
