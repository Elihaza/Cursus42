/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 14:06:48 by ellarbi           #+#    #+#             */
/*   Updated: 2020/08/02 23:21:41 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "libft.h"

int			check_for_duplicate(t_file_state *file_state)
{
	t_list	*found_keys;
	t_list	*tmp;

	found_keys = file_state->found_keys;
	while (found_keys)
	{
		tmp = found_keys->next;
		while (tmp)
		{
			if (ft_strcmp(tmp->name, found_keys->name) == OK)
				return (ERR);
			tmp = tmp->next;
		}
		found_keys = found_keys->next;
	}
	return (OK);
}

static int	is_too_close_from_empty(t_data *data, int x, int y)
{
	if (y - 1 < 0 || data->map[y - 1][x] == ' ')
		return (ERR);
	if (x + 1 >= data->map_width || data->map[y][x + 1] == ' ')
		return (ERR);
	if (y + 1 >= data->map_height || data->map[y + 1][x] == ' ')
		return (ERR);
	if (x - 1 < 0 || data->map[y][x - 1] == ' ')
		return (ERR);
	return (OK);
}

int			is_map_closed(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_height)
	{
		x = 0;
		while (x < data->map_width)
		{
			if (data->map[y][x] == '0' || data->map[y][x] == '2')
				if (is_too_close_from_empty(data, x, y))
					return (ERR_MAP_NOT_CLOSE);
			x++;
		}
		y++;
	}
	return (OK);
}

char		*get_value_after_key(char *line)
{
	while (*line && !(*line == '\f' || *line == '\t' || *line == ' ' ||
					*line == '\n' || *line == '\r' || *line == '\v'))
		line++;
	while (*line && (*line == '\f' || *line == '\t' || *line == ' ' ||
					*line == '\n' || *line == '\r' || *line == '\v'))
		line++;
	return (line);
}

int			random_fn(char **splitted, int code, int *var_to_set)
{
	if (var_to_set)
		*var_to_set = 1;
	ft_clear_splitted(splitted);
	return (code);
}
