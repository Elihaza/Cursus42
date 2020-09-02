/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 17:58:20 by frdescam          #+#    #+#             */
/*   Updated: 2020/08/02 23:48:00 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "../cub3d.h"
# include "libft.h"

int				init(int argc, char **argv, t_data **data);
int				read_input_file(int fd, t_data *data);
int				check_line_validity(char *line, t_file_state *file_state);
int				compute_data(t_data *data);
int				check_color_validity(char *line, t_file_state *file_state);
int				check_texture_validity(char *line,
					t_file_state *file_state);
int				check_map_validity(char *line, t_file_state *file_state);
int				check_resolution_validity(char **splitted,
					t_file_state *file_state);
int				extract_line_content(char *line, t_file_state *file_state,
					t_data *data);
int				check_for_duplicate(t_file_state *file_state);
int				is_map_closed(t_data *data);
char			*get_value_after_key(char *line);
int				random_fn(char **splitted, int code, int *var_to_set);

#endif
