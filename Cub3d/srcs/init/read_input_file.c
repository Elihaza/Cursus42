/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 15:59:57 by ellarbi           #+#    #+#             */
/*   Updated: 2020/08/02 23:56:16 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include "init.h"

void	init_file_state(t_file_state **file_state)
{
	if (!(*file_state = malloc(sizeof(t_file_state))))
		return ;
	(*file_state)->is_current_line_texture = 0;
	(*file_state)->is_current_line_color = 0;
	(*file_state)->is_current_line_resolution = 0;
	(*file_state)->is_current_line_map = 0;
	(*file_state)->has_map_started = 0;
	(*file_state)->player_already_found = 0;
	(*file_state)->found_keys = NULL;
	(*file_state)->empty_line_after_map = 0;
}

void	reset_file_state(t_file_state *file_state)
{
	file_state->is_current_line_texture = 0;
	file_state->is_current_line_color = 0;
	file_state->is_current_line_resolution = 0;
	file_state->is_current_line_map = 0;
}

void	clear_file_state(t_file_state *file_state)
{
	ft_lstclear(&file_state->found_keys, &free);
}

int		missing_data(t_data *data, t_file_state *file_state)
{
	if (!data->map)
		return (ERR_MISSING_MAP);
	if (!data->textures_paths.north)
		return (ERR_MISSING_NO);
	if (!data->textures_paths.south)
		return (ERR_MISSING_SO);
	if (!data->textures_paths.east)
		return (ERR_MISSING_EA);
	if (!data->textures_paths.west)
		return (ERR_MISSING_WE);
	if (data->color_textures.sky == -1)
		return (ERR_MISSING_C);
	if (data->color_textures.floor == -1)
		return (ERR_MISSING_F);
	if (!data->textures_paths.sprite)
		return (ERR_MISSING_S);
	if (data->mlx.mlx_width == -1)
		return (ERR_MISSING_R);
	if (!file_state->player_already_found)
		return (ERR_NO_PLAYER);
	return (OK);
}

int		read_input_file(int fd, t_data *data)
{
	int				status;
	int				ret_code;

	init_file_state(&data->file_state);
	while ((status = get_next_line(fd, &data->line)) > 0)
	{
		if ((ret_code = check_line_validity(data->line, data->file_state)))
			return (ret_code);
		if ((ret_code = extract_line_content(data->line, data->file_state,
						data)))
			return (ret_code);
		reset_file_state(data->file_state);
		free(data->line);
	}
	free(data->line);
	if (check_for_duplicate(data->file_state) != OK)
		return (ERR_DUP_KEY);
	if ((ret_code = missing_data(data, data->file_state)) != OK)
		return (ret_code);
	clear_file_state(data->file_state);
	if (status == -1)
		return (ERR);
	return (OK);
}
