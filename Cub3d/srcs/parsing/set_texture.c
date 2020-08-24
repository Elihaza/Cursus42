/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:40:51 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/25 14:14:34 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_texture(t_parameters *params, t_texture *t, const char *line)
{
	char	*path;
	int		i[3];

	if (t->id)
		quit_program(params, "texture already set.");
	path = ft_strtrim(line, " ");
	if (path == NULL)
		quit_program(params, "set_texture: allocation failed.");
	t->id = mlx_xpm_file_to_image(
		params->mlx_id, path, &(t->width), &(t->height)
);
	free(path);
	if (t->id == NULL)
		quit_program(params, "Can't load texture file.");
	t->img = (int*)mlx_get_data_addr(t->id, &i[0], &i[1], &i[2]);
	if (t->img == NULL)
		quit_program(params, "Can't load texture file.");
}
