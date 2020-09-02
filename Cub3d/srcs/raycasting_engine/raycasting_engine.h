/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_engine.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:33:31 by frdescam          #+#    #+#             */
/*   Updated: 2020/07/25 13:23:23 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_ENGINE_H
# define RAYCASTING_ENGINE_H

# include "../cub3d.h"
# include "libft.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct	s_angle
{
	double deg_abs;
	double deg_rel;
	double rad_abs;
	double rad_rel;
}				t_angle;

typedef struct	s_ray
{
	double	ray_len;
	char	wall_orientation;
	double	impact_x;
	double	impact_y;
	t_list	*sprites;
}				t_ray;

typedef struct	s_sprite
{
	double	pos_x;
	double	pos_y;
	double	distance_from_player;
	double	impact_distance;
	double	angle_sprite;
	double	angle_sprite_ray;
	double	texture_column;
}				t_sprite;

t_ray			get_x_first_quarter_ray_len(t_data *data, t_angle *angle);
t_ray			get_x_second_quarter_ray_len(t_data *data, t_angle *angle);
t_ray			get_x_third_quarter_ray_len(t_data *data, t_angle *angle);
t_ray			get_x_last_quarter_ray_len(t_data *data, t_angle *angle);
t_ray			get_y_first_quarter_ray_len(t_data *data, t_angle *angle);
t_ray			get_y_second_quarter_ray_len(t_data *data, t_angle *angle);
t_ray			get_y_third_quarter_ray_len(t_data *data, t_angle *angle);
t_ray			get_y_last_quarter_ray_len(t_data *data, t_angle *angle);
void			handle_sprite_detection(t_ray *ray, t_data *data,
						t_angle *angle, char ray_type);
t_ray			get_ray(t_data *data, double angle, double offset);
void			set_angle(t_angle *angle, double angle_deg_abs);
void			remove_sprite(t_list *prev, t_list **elem, t_ray *ray);
int				is_same_x_top(t_sprite *new_sprite, t_data *data, t_ray *ray);
int				is_same_x_bottom(t_sprite *new_sprite, t_data *data,
						t_ray *ray);
int				is_same_y_left(t_sprite *new_sprite, t_data *data, t_ray *ray);
int				is_same_y_right(t_sprite *new_sprite, t_data *data, t_ray *ray);
void			handle_sprite_detection7(t_angle *angle_ray,
					t_sprite *new_sprite);
void			handle_sprite_detection6(t_angle *angle_ray,
					t_sprite *new_sprite);
void			handle_sprite_detection5(t_ray *ray, t_data *data,
					t_angle *angle_ray, t_sprite *new_sprite);
void			handle_sprite_detection4(t_ray *ray, t_data *data,
					t_angle *angle_ray, t_sprite *new_sprite);
void			handle_sprite_detection3(t_ray *ray, t_data *data,
				t_angle *angle_ray, t_sprite *new_sprite);

#endif
