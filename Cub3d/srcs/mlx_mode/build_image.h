/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_image.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:26:06 by ellarbi           #+#    #+#             */
/*   Updated: 2020/06/02 15:01:12 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILD_IMAGE_H
# define BUILD_IMAGE_H

# include "libft.h"

typedef struct	s_img
{
	void		*img;
	int			*data;
	int			bpp;
	int			size;
	int			endian;
}				t_img;
typedef struct	s_column
{
	char		wall_orientation;
	int			column;
	int			height;
	int			start;
	int			end;
	double		impact_x;
	double		impact_y;
	t_list		*sprites;
}				t_column;

int				get_sky_color(t_data *data);
int				get_floor_color(t_data *data);
int				get_wall_color(t_data *data, t_column *column, int line);
int				get_sprite_color(t_data *data, t_column *column, int line,
					int *px);
int				build_image(t_data *data, t_img **img);

#endif
