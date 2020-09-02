/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:17:21 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/22 17:14:45 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_params(t_parameters *params, const char *filepath)
{
	int		fd;
	int		i;
	int		l;
	char	*line;

	fd = validate_file(params, filepath);
	l = 0;
	while (get_next_line(fd, &line))
	{
		i = 0;
		while (line[i] == 32)
			i++;
		if (line[i] && ft_isalpha(line[i]))
			set_params(params, &line[i]);
		else if (line[i] && line[i] == '1')
			params->map_h += 1;
		l = params->map_h > 0 ? l : l + 1;
		free(line);
	}
	free(line);
	close(fd);
	set_map(params, &line, l);
	set_sprites(params);
	if (validate_params(params) == 0)
		quit_program(params, "Configuration incomplete.");
}
