/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:00:07 by ellarbi           #+#    #+#             */
/*   Updated: 2020/07/26 17:46:26 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include "init.h"
#include "libft.h"
#include "mlx.h"

static int	load_texture(t_data *data, t_texture_img *texture_img,
		char *texture_path)
{
	if (!(texture_img->img = mlx_xpm_file_to_image(
			data->mlx.mlx_id,
			texture_path,
			&texture_img->width,
			&texture_img->height)))
		return (ERR_MLX);
	if (!(texture_img->data = (int *)mlx_get_data_addr(
			texture_img->img,
			&texture_img->bpp,
			&texture_img->size,
			&texture_img->endian)))
		return (ERR_MLX);
	return (OK);
}

static void	handle_player(t_data *data, char *player, int pos_x, int pos_y)
{
	if (*player == 'N')
		data->player.orientation = 0;
	if (*player == 'S')
		data->player.orientation = 180;
	if (*player == 'E')
		data->player.orientation = 90;
	if (*player == 'W')
		data->player.orientation = 270;
	data->player.pos_x = pos_x + 0.5;
	data->player.pos_y = pos_y + 0.5;
	*player = '0';
}

static int	compute_line_map(t_data *data, int line_index, int line_len)
{
	char	*tmp;
	int		i;

	if (line_len < data->map_width)
	{
		if (!(tmp = malloc(sizeof(char) * (data->map_width + 1))))
			return (ERR_MALLOC);
		i = 0;
		while (data->map[line_index][i])
		{
			tmp[i] = data->map[line_index][i];
			i++;
		}
		while (i < data->map_width)
		{
			tmp[i] = ' ';
			i++;
		}
		tmp[i] = '\0';
		free(data->map[line_index]);
		data->map[line_index] = tmp;
	}
	return (OK);
}

static int	compute_map(t_data *data)
{
	int	i;
	int	j;

	while (data->map[data->map_height])
	{
		if (data->map_width < (int)ft_strlen(data->map[data->map_height]))
			data->map_width = ft_strlen(data->map[data->map_height]);
		data->map_height++;
	}
	i = 0;
	while (i < data->map_height)
	{
		if (compute_line_map(data, i, ft_strlen(data->map[i])) != OK)
			return (ERR_MALLOC);
		j = 0;
		while (j < data->map_width)
		{
			if (ft_strchr("NSEW", data->map[i][j]))
				handle_player(data, &data->map[i][j], j, i);
			j++;
		}
		i++;
	}
	return (OK);
}

int			compute_data(t_data *data)
{
	int		ret_code;

	if ((ret_code = load_texture(data, &data->mlx.north_texture,
								data->textures_paths.north)) != OK)
		return (ret_code);
	if ((ret_code = load_texture(data, &data->mlx.south_texture,
								data->textures_paths.south)) != OK)
		return (ret_code);
	if ((ret_code = load_texture(data, &data->mlx.east_texture,
								data->textures_paths.east)) != OK)
		return (ret_code);
	if ((ret_code = load_texture(data, &data->mlx.west_texture,
								data->textures_paths.west)) != OK)
		return (ret_code);
	if ((ret_code = load_texture(data, &data->mlx.sprite_texture,
								data->textures_paths.sprite)) != OK)
		return (ret_code);
	if ((ret_code = compute_map(data)) != OK)
		return (ret_code);
	return (OK);
}
