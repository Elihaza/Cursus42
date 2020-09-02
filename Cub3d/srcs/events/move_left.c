/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:14:09 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/21 18:16:44 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move_left(t_parameters *p)
{
	double ndirx;
	double ndiry;

	ndirx = -p->diry;
	ndiry = p->dirx;
	if (p->map[(int)(p->posx + ndirx * MOVESPEED)][(int)p->posy] == '0')
		p->posx += ndirx * MOVESPEED;
	if (p->map[(int)p->posx][(int)(p->posy + ndiry * MOVESPEED)] == '0')
		p->posy += ndiry * MOVESPEED;
}
