/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:40:20 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/25 13:37:56 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_map(t_parameters *params, char **line, int l)
{
	int		h;
	int		fd;
	char	**tmp;

	if (params->map_h < 3)
		quit_program(params, "invalid map.");
	if (!(tmp = (char**)malloc(sizeof(char*) * params->map_h)))
		quit_program(params, "Map: malloc failed.");
	if ((fd = open(params->config_file, O_RDONLY)) < 3)
		quit_program(params, "Can't reopen file.");
	h = -1;
	while (++h < l && get_next_line(fd, line))
		free(*line);
	h = -1;
	while (++h < params->map_h && get_next_line(fd, line))
	{
		tmp[h] = ft_strctrim(*line, ' ');
		free(*line);
	}
	close(fd);
	params->map_w = ft_strlen(tmp[0]);
	params->map = tmp;
	if (validate_map(params) == 0)
		quit_program(params, "Invalid map.");
}
