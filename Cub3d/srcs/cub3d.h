/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 18:31:02 by ellarbi           #+#    #+#             */
/*   Updated: 2020/08/02 23:51:13 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"

# define OK 0
# define ERR 1
# define ERR_TOO_FEW_ARGS 10
# define ERR_TOO_MUCH_ARGS 11
# define ERR_UK_ARG  12
# define ERR_NOT_CUB_MAP 13

# define ERR_OPEN_MAP 20
# define ERR_EOF_UNTIMELY 21
# define ERR_EMPTY_LINE_MAP 22
# define ERR_SX_UK_KEY 23
# define ERR_SX_TOO_FEW_VAL 24
# define ERR_SX_TOO_MUCH_VAL 25
# define ERR_OPEN_TX 26
# define ERR_DUP_KEY 27

# define ERR_SX_COLOR 28

# define ERR_COLOR_VAL 29
# define ERR_SX_RES 30
# define ERR_SX_MAP 31
# define ERR_TOO_MUCH_PLAYER 32

# define ERR_MISSING_MAP 33
# define ERR_MISSING_NO 34
# define ERR_MISSING_SO 35
# define ERR_MISSING_EA 36
# define ERR_MISSING_WE 37
# define ERR_MISSING_C 38
# define ERR_MISSING_F 39
# define ERR_MISSING_S 40
# define ERR_MISSING_R 41
# define ERR_KEY_ON_MAP 42
# define ERR_MAP_NOT_CLOSE 43
# define ERR_NO_PLAYER 44
# define ERR_RES_TOO_LOW 45
# define ERR_WRITING_BMP 46
# define ERR_MAP_NOT_LAST 47

# define ERR_MLX 50
# define ERR_MALLOC 51

typedef struct	s_file_state
{
	int				is_current_line_texture;
	int				is_current_line_color;
	int				is_current_line_resolution;
	int				is_current_line_map;
	int				has_map_started;
	int				player_already_found;
	int				empty_line_after_map;
	t_list			*found_keys;
}				t_file_state;

typedef struct	s_texture_img
{
	int					width;
	int					height;
	int					bpp;
	int					size;
	int					endian;
	void				*img;
	int					*data;
}				t_texture_img;

typedef struct	s_player
{
	double				pos_x;
	double				pos_y;
	double				orientation;
}				t_player;

typedef struct	s_mlx
{
	void				*mlx_id;
	void				*mlx_window_id;
	int					mlx_width;
	int					mlx_height;
	t_texture_img		north_texture;
	t_texture_img		south_texture;
	t_texture_img		east_texture;
	t_texture_img		west_texture;
	t_texture_img		sprite_texture;
}				t_mlx;

typedef struct	s_textures_paths
{
	char				*north;
	char				*south;
	char				*east;
	char				*west;
	char				*sprite;
}				t_textures_paths;

typedef struct	s_color_textures
{
	int					floor;
	int					sky;
}				t_color_textures;

typedef struct	s_data
{
	t_player			player;
	t_mlx				mlx;
	t_textures_paths	textures_paths;
	t_color_textures	color_textures;
	char				**map;
	int					map_width;
	int					map_height;
	int					keylist[280];
	char				*line;
	t_file_state		*file_state;
}				t_data;

#endif
