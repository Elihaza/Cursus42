/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:41:22 by ellarbi           #+#    #+#             */
/*   Updated: 2020/06/02 15:48:21 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_PLAYER_H
# define MOVE_PLAYER_H

# include "../cub3d.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct	s_move
{
	double	x_shift;
	double	y_shift;
	double	offset_wall_x;
	double	offset_wall_y;
}				t_move;

t_move			get_move(int angle);
void			move_player_up(t_data *data);
void			move_player_down(t_data *data);
void			move_player_right(t_data *data);
void			move_player_left(t_data *data);

#endif
