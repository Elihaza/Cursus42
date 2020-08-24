/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textured_stripe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:27:00 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:31:33 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static t_texture	texture_for(int n, t_parameters p)
{
	if (n == NORTH)
		return (p.north_texture);
	if (n == SOUTH)
		return (p.south_texture);
	if (n == WEST)
		return (p.west_texture);
	if (n == EAST)
		return (p.east_texture);
	return (p.north_texture);
}

static void			draw_ceiling(int **buffer, int s, int ds, int color)
{
	int i;

	i = 0;
	while (i < ds)
	{
		buffer[i][s] = color;
		i++;
	}
}

void				draw_floor(
					int **buffer, int s, t_dda_parameters dda, t_parameters p)
{
	int i;

	i = dda.liney;
	while (i < p.win_h && i >= 0)
	{
		buffer[i][s] = p.floor_color;
		i++;
	}
}

void				draw_textured_stripe(
					int **buf, int s, t_dda_parameters dda, t_parameters p)
{
	t_texture	texture;
	int			tex_x;
	int			tex_y;
	int			i;
	double		tex_pos;

	texture = texture_for(dda.side, p);
	tex_x = (int)(dda.wallx * (double)texture.width);
	if ((dda.side == NORTH || dda.side == SOUTH) && dda.raydirx > 0)
		tex_x = (double)texture.width - tex_x - 1;
	else if ((dda.side == WEST || dda.side == EAST) && dda.raydiry < 0)
		tex_x = (double)texture.width - tex_x - 1;
	tex_pos = (dda.linex - p.win_h / 2 + dda.lineheight / 2)
			* 1.0 * texture.height / dda.lineheight;
	i = dda.linex - 1;
	while (++i < dda.liney)
	{
		tex_y = (int)tex_pos & (texture.height - 1);
		tex_pos += 1.0 * texture.height / dda.lineheight;
		buf[i][s] = (int)(texture.img[texture.height * tex_y + tex_x]);
	}
	draw_ceiling(buf, s, dda.linex, p.ceiling_color);
	draw_floor(buf, s, dda, p);
}
