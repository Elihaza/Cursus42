/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:52:18 by frdescam          #+#    #+#             */
/*   Updated: 2020/06/02 15:52:19 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANDLE_EVENTS_H
# define HANDLE_EVENTS_H

int		handle_moves(t_data *data);
int		handle_keypress(int keycode, t_data *data);
int		handle_keyrelease(int keycode, t_data *data);

#endif
