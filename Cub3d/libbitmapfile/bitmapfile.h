/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmapfile.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:52:25 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/18 15:13:10 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAPFILE_H
# define BITMAPFILE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef union	u_dint2
{
	int				i;
	unsigned char	d[2];
}				t_dint2;

typedef union	u_dint4
{
	int				i;
	unsigned char	d[4];
}				t_dint4;

typedef struct	s_bitmapfileheader
{
	t_dint2			filetype;
	t_dint4			filesize;
	t_dint4			reserved;
	t_dint4			pixeldata_offset;
}				t_bitmapfileheader;

typedef struct	s_bitmapinfoheader
{
	t_dint4		headersize;
	t_dint4		img_width;
	t_dint4		img_height;
	t_dint2		planes;
	t_dint2		bpp;
	t_dint4		compression;
	t_dint4		img_size;
	t_dint4		xpixelspermeter;
	t_dint4		ypixelspermeter;
	t_dint4		totalcolors;
	t_dint4		importantcolors;

}				t_bitmapinfoheader;

void			dint4cpy(t_dint4 n, unsigned char *dest);
void			write_bmpinfoheader(int fd, t_bitmapinfoheader bmpih);
void			write_bmpfileheader(int fd, t_bitmapfileheader bmpfh);
int				write_pixeldata(int fd, t_bitmapinfoheader bmpih, int **img);
int				create_bmpfile(const char *path, int width,
						int height, int **buf);
#endif
