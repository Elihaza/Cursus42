/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_engine_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 15:36:49 by frdescam          #+#    #+#             */
/*   Updated: 2020/07/22 17:26:37 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_engine.h"

void	remove_sprite(t_list *prev, t_list **elem, t_ray *ray)
{
	t_list *tmp;

	if (prev)
		prev->next = (*elem)->next;
	else
		ray->sprites = (*elem)->next;
	tmp = (*elem)->next;
	ft_lstdelone(*elem, free);
	*elem = tmp;
}

void	set_angle(t_angle *angle, double angle_deg_abs)
{
	angle->deg_abs = angle_deg_abs;
	angle->rad_abs = angle->deg_abs * M_PI / 180;
	if (angle->deg_abs < 90.0)
		angle->deg_rel = 90.0 - angle->deg_abs;
	else if (angle->deg_abs < 180)
		angle->deg_rel = angle->deg_abs - 90;
	else if (angle->deg_abs < 270)
		angle->deg_rel = 270 - angle->deg_abs;
	else
		angle->deg_rel = angle->deg_abs - 270;
	angle->rad_rel = angle->deg_rel * M_PI / 180;
}
