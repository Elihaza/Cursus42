/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_bmpfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:06:31 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/18 15:13:37 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitmapfile.h"

static void	set_bmpinfoheader(t_bitmapinfoheader *ih, int w, int h)
{
	ih->headersize.i = 40;
	ih->img_width.i = w;
	ih->img_height.i = h;
	ih->planes.i = 1;
	ih->bpp.i = 32;
	ih->compression.i = 0;
	ih->img_size.i = 0;
	ih->xpixelspermeter.i = 0;
	ih->ypixelspermeter.i = 0;
	ih->totalcolors.i = 0;
	ih->importantcolors.i = 0;
}

static void	set_bmpfileheader(t_bitmapfileheader *fh, t_bitmapinfoheader ih)
{
	unsigned int bpp;

	bpp = ih.bpp.i / 8;
	fh->filetype.i = 19778;
	fh->filesize.i = 54 + ((bpp * ih.img_width.i) * (bpp * ih.img_height.i));
	fh->reserved.i = 0;
	fh->pixeldata_offset.i = 54;
}

int			create_bmpfile(const char *path, int width, int height, int **buf)
{
	int					fd;
	t_bitmapfileheader	bmpfh;
	t_bitmapinfoheader	bmpih;

	if ((fd = open(path, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU)) < 3)
		return (-1);
	set_bmpinfoheader(&bmpih, width, height);
	set_bmpfileheader(&bmpfh, bmpih);
	write_bmpfileheader(fd, bmpfh);
	write_bmpinfoheader(fd, bmpih);
	if (write_pixeldata(fd, bmpih, buf) == -1)
		return (-1);
	close(fd);
	return (0);
}
