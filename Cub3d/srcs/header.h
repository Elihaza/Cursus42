/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:48:56 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/25 12:58:49 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# include "../libmlx/mlx.h"
# include "../libft/libft.h"
# include "../libbitmapfile/bitmapfile.h"

typedef struct	s_texture
{
	void	*id;
	int		*img;
	int		width;
	int		height;
}				t_texture;

typedef struct	s_sprite
{
	double	x;
	double	y;
	double	distance;
}				t_sprite;

typedef struct	s_sprites_parameters
{
	double	invdet;
	double	transformx;
	double	transformy;
	int		screenx;
	int		h;
	int		w;
	int		dstart_x;
	int		dstart_y;
	int		dend_x;
	int		dend_y;
	int		tex_x;
}				t_sprites_parameters;

typedef struct	s_parameters
{
	char		*config_file;
	int			win_h;
	int			win_w;
	int			map_h;
	int			map_w;
	char		**map;
	int			nsprite;
	t_sprite	*sprites;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	void		*mlx_id;
	void		*win_id;
	void		*img_id;
	int			endian;
	int			bpp;
	int			line_size;
	void		*img;
	t_texture	north_texture;
	t_texture	south_texture;
	t_texture	west_texture;
	t_texture	east_texture;
	t_texture	sprite_texture;
	int			floor_color;
	int			ceiling_color;
}				t_parameters;

typedef struct	s_dda_parameters
{
	double	camerax;
	double	raydirx;
	double	raydiry;
	int		mapx;
	int		mapy;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	int		stepx;
	int		stepy;
	int		hit;
	int		side;
	int		lineheight;
	int		linex;
	int		liney;
	double	wallx;

}				t_dda_parameters;

# define MOVESPEED 0.16
# define ROTSPEED 0.09

# define MAX_WINDOW_WIDTH 2560
# define MAX_WINDOW_HEIGHT 1440

# define NORTH 3
# define SOUTH 4
# define EAST 5
# define WEST 6

# define DK_LEFT 123
# define DK_RIGHT 124
# define K_W 13
# define K_A 0
# define K_S 1
# define K_D 2
# define K_ESC 53

/* root srcs */
void			save_scene(t_parameters *params);
void			display_scene(t_parameters params);
void			quit_program(t_parameters *params, const char *error_msg);

/* init */
void			set_params_to_default(t_parameters *params);
void			init_params(t_parameters *params, const char *filepath);
int				validate_params(t_parameters *params);

/* init */
void			initialize_mlx_window(t_parameters *p);
void			initialize_cub3d(t_parameters *params, const char *arg1);

/* parsing */
int				validate_file(t_parameters *params, const char *filepath);
void			set_params(t_parameters *params, const char *line);
void			set_resolution(t_parameters *params, const char *line);
void			set_texture(
				t_parameters *params, t_texture *t, const char *line);
void			set_floor_color(t_parameters *params, const char *line);
void			set_ceiling_color(t_parameters *params, const char *line);
void			set_map(t_parameters *params, char **line, int l);
int				validate_map(t_parameters *params);
void			set_player_position(t_parameters *params, int c, int x, int y);
int				validate_line_type1(char *map_line, int len);
int				validate_line_type2(
					char *map_line, int l, t_parameters *params);
void			set_sprites(t_parameters *p);

/* raycasting */
void			dda_init(
				t_parameters params, t_dda_parameters *dda, int screen_slice);
void			dda_perform(t_dda_parameters *dda, char **map);
void			dda_data(t_dda_parameters *dda, t_parameters p, double *z);
void			draw_textured_stripe(
				int **buf, int s, t_dda_parameters dda, t_parameters p);
void			sort_sprites(t_sprite *sprites, int array_size);
void			sprites_distance(
				t_sprite *sprites, int size, int posx, int posy);
void			draw_sprites(int **buf, t_parameters p, double *zbuffer);

/* utils */
int				**draw_scene(t_parameters tmp);
void			buffer_to_image(int h, int w, int **buf, void **img);

/* events */
int				key_hook(int keycode, void *params);
int				close_button(t_parameters *p);
void			camera_left(t_parameters *p);
void			camera_right(t_parameters *p);
void			move_forward(t_parameters *p);
void			move_backward(t_parameters *p);
void			move_left(t_parameters *p);
void			move_right(t_parameters *p);

#endif
