/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:06:20 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/16 09:15:58 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		validate_file(t_parameters *params, const char *filepath)
{
	int fd;

	if (ft_strcmp(ft_strrchr(filepath, '.'), ".cub"))
		quit_program(params, "Configuration file: not a .cub file.");
	fd = open(filepath, O_RDONLY);
	if (fd < 3)
		quit_program(params, "Configuration file: can't open file.");
	params->config_file = (char*)filepath;
	return (fd);
}
