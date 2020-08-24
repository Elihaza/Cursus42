/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:31:58 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:35:09 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	init_calculations(
			double x, double y, t_sprites_parameters *s, t_parameters p)
{
	x = x - p.posx + 0.5;
	y = y - p.posy + 0.5;
	s->invdet = 1.0 / (p.planex * p.diry - p.dirx * p.planey);
	s->transformx = s->invdet * (p.diry * x - p.dirx * y);
	s->transformy = s->invdet * (-p.planey * x + p.planex * y);
	s->screenx = (int)((p.win_w / 2) * (1 + s->transformx / s->transformy));
	s->h = abs((int)(p.win_h / (s->transformy)));
	s->dstart_y = -s->h / 2 + p.win_h / 2;
	s->dstart_y = s->dstart_y < 0 ? 0 : s->dstart_y;
	s->dend_y = s->h / 2 + p.win_h / 2;
	s->dend_y = s->dend_y >= p.win_h ? p.win_h - 1 : s->dend_y;
	s->w = abs((int)(p.win_h / (s->transformy)));
	s->dstart_x = -s->w / 2 + s->screenx;
	s->dstart_x = s->dstart_x < 0 ? 0 : s->dstart_x;
	s->dend_x = s->w / 2 + s->screenx;
	s->dend_x = s->dend_x >= p.win_w ? p.win_w - 1 : s->dend_x;
}

static int	set_tex_x(t_sprites_parameters s, int texw)
{
	return (
		(256 * (s.dstart_x - (-s.w / 2 + s.screenx)) * texw / s.w) / 256
);
}

static int	get_tex_y(t_sprites_parameters s, int pxl, t_parameters p)
{
	return (
		((((pxl) * 256 - p.win_h * 128 + s.h * 128)
			* p.sprite_texture.height) / s.h) / 256
);
}

static void	draw_sprite(
			int **buf, t_sprites_parameters s, t_parameters p, double *zbuffer)
{
	int j;
	int pixel_color;

	while (s.dstart_x < s.dend_x)
	{
		s.tex_x = set_tex_x(s, p.sprite_texture.width);
		j = s.dstart_y - 1;
		if (s.transformy > 0 && s.dstart_x > 0 && s.dstart_x < p.win_w
			&& s.transformy < zbuffer[s.dstart_x])
			while (++j < s.dend_y)
			{
				pixel_color = p.sprite_texture.img[
					p.sprite_texture.width
					* get_tex_y(s, j, p) + s.tex_x
				];
				if (pixel_color != 0)
					buf[j][s.dstart_x] = pixel_color;
			}
		(s.dstart_x)++;
	}
}

void		draw_sprites(int **buf, t_parameters p, double *zbuffer)
{
	t_sprites_parameters	s;
	int						i;

	sprites_distance(p.sprites, p.nsprite, p.posx, p.posy);
	sort_sprites(p.sprites, p.nsprite);
	i = -1;
	while (++i < p.nsprite)
	{
		init_calculations(p.sprites[i].x, p.sprites[i].y, &s, p);
		draw_sprite(buf, s, p, zbuffer);
	}
}
