/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_validity_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 19:00:27 by ellarbi           #+#    #+#             */
/*   Updated: 2020/08/02 20:14:59 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include "init.h"

int	check_color_value(char **splitted)
{
	int	i;
	int	j;

	i = 1;
	while (i < 4)
	{
		j = 0;
		while (splitted[i][j])
		{
			if (!ft_strchr("0123456789", splitted[i][j]))
				return (ERR_SX_COLOR);
			j++;
		}
		if (ft_atoi(splitted[i]) > 255)
			return (ERR_COLOR_VAL);
		i++;
	}
	return (OK);
}

int	check_color_validity(char *line, t_file_state *file_state)
{
	char	**splitted;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (line[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		return (ERR_SX_COLOR);
	if (!(splitted = ft_split(line, ",\f\t \n\r\v ")))
		return (ERR_MALLOC);
	if (splitted[0] && splitted[1] && splitted[2] && splitted[3] && splitted[4])
		return (ERR_SX_COLOR);
	if (!splitted[0] || !splitted[1] || !splitted[2] || !splitted[3])
		return (ERR_SX_COLOR);
	if (check_color_value(splitted) != OK)
		return (check_color_value(splitted));
	file_state->is_current_line_color = 1;
	ft_clear_splitted(splitted);
	return (OK);
}

int	check_texture_validity(char *line, t_file_state *file_state)
{
	int		fd;
	char	*path;

	path = get_value_after_key(line);
	if ((fd = open(path, O_RDONLY)) == -1)
		return (ERR_OPEN_TX);
	close(fd);
	file_state->is_current_line_texture = 1;
	return (OK);
}

int	check_map_validity(char *line, t_file_state *file_state)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr("012NSEW ", line[i]))
			return (ERR_SX_MAP);
		if (ft_strchr("NSEW", line[i]))
		{
			if (!file_state->player_already_found)
				file_state->player_already_found = 1;
			else
				return (ERR_TOO_MUCH_PLAYER);
		}
		i++;
	}
	file_state->has_map_started = 1;
	file_state->is_current_line_map = 1;
	return (OK);
}

int	check_resolution_validity(char **splitted, t_file_state *file_state)
{
	int	i;

	if (splitted[0] && splitted[1] && splitted[2] && splitted[3])
		return (ERR_SX_TOO_MUCH_VAL);
	if (!splitted[0] || !splitted[1] || !splitted[2])
		return (ERR_SX_TOO_FEW_VAL);
	i = 0;
	while (splitted[1][i])
	{
		if (!ft_strchr("0123456789", splitted[1][i]))
			return (ERR_SX_RES);
		i++;
	}
	i = 0;
	while (splitted[2][i])
	{
		if (!ft_strchr("0123456789", splitted[2][i]))
			return (ERR_SX_RES);
		i++;
	}
	if (ft_atoi(splitted[1]) == 0 || ft_atoi(splitted[2]) == 0)
		return (ERR_RES_TOO_LOW);
	file_state->is_current_line_resolution = 1;
	return (OK);
}
