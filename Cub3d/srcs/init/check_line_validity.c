/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_validity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 18:53:30 by frdescam          #+#    #+#             */
/*   Updated: 2020/08/03 15:15:14 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "init.h"

static int	is_color(char **splitted, t_file_state *file_state)
{
	if (ft_strcmp("C", splitted[0]) == OK ||
		ft_strcmp("F", splitted[0]) == OK)
	{
		ft_lstadd_back(
				&file_state->found_keys,
				ft_lstnew(splitted[0],
				(void *)0));
		return (1);
	}
	return (0);
}

static int	is_texture(char **splitted, t_file_state *file_state)
{
	if (ft_strcmp("S", splitted[0]) == OK ||
		ft_strcmp("NO", splitted[0]) == OK ||
		ft_strcmp("SO", splitted[0]) == OK ||
		ft_strcmp("EA", splitted[0]) == OK ||
		ft_strcmp("WE", splitted[0]) == OK)
	{
		ft_lstadd_back(
				&file_state->found_keys,
				ft_lstnew(splitted[0],
				(void *)0));
		return (1);
	}
	return (0);
}

static int	is_resolution(char **splitted, t_file_state *file_state)
{
	if (ft_strcmp("R", splitted[0]) == OK)
	{
		ft_lstadd_back(
				&file_state->found_keys,
				ft_lstnew(splitted[0],
				(void *)0));
		return (1);
	}
	return (0);
}

static int	is_map(char **splitted)
{
	if (splitted[0][0] == '1' || splitted[0][0] == '0')
		return (1);
	return (0);
}

int			check_line_validity(char *line, t_file_state *file_state)
{
	char	**splitted;
	int		ret_code;

	if (!(splitted = ft_split(line, "\f\t \n\r\v")))
		return (ERR_MALLOC);
	if (!*splitted && file_state->has_map_started)
		return (random_fn(splitted, OK, &file_state->empty_line_after_map));
	else if (!*splitted)
		return (random_fn(splitted, OK, NULL));
	else if (*splitted && (file_state->empty_line_after_map ||
				(!is_map(splitted) && file_state->has_map_started)))
		return (random_fn(splitted, ERR_MAP_NOT_LAST, NULL));
	if (is_color(splitted, file_state))
		ret_code = check_color_validity(line, file_state);
	else if (is_texture(splitted, file_state))
		ret_code = check_texture_validity(line, file_state);
	else if (is_map(splitted))
		ret_code = check_map_validity(line, file_state);
	else if (is_resolution(splitted, file_state))
		ret_code = check_resolution_validity(splitted, file_state);
	else
		return (random_fn(splitted, ERR_SX_UK_KEY, NULL));
	ft_clear_splitted(splitted);
	return (ret_code);
}
