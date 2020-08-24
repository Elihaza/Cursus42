/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_bmpfileheader.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:06:11 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/18 14:06:16 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmapfile.h"

void	write_bmpfileheader(int fd, t_bitmapfileheader bmpfh)
{
	unsigned char buf[14];

	buf[0] = bmpfh.filetype.d[0];
	buf[1] = bmpfh.filetype.d[1];
	dint4cpy(bmpfh.filesize, &buf[2]);
	dint4cpy(bmpfh.reserved, &buf[6]);
	dint4cpy(bmpfh.pixeldata_offset, &buf[10]);
	write(fd, buf, 14);
}
