/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_line_content.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 13:46:17 by ellarbi           #+#    #+#             */
/*   Updated: 2020/08/03 15:43:06 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "init.h"
#include "mlx.h"

static int	extract_texture(char **splitted, char *line, t_data *data)
{
	char	*path;

	path = get_value_after_key(line);
	if (ft_strcmp(splitted[0], "NO") == OK && !data->textures_paths.north)
		if (!(data->textures_paths.north = ft_strdup(path)))
			return (ERR_MALLOC);
	if (ft_strcmp(splitted[0], "SO") == OK && !data->textures_paths.south)
		if (!(data->textures_paths.south = ft_strdup(path)))
			return (ERR_MALLOC);
	if (ft_strcmp(splitted[0], "EA") == OK && !data->textures_paths.east)
		if (!(data->textures_paths.east = ft_strdup(path)))
			return (ERR_MALLOC);
	if (ft_strcmp(splitted[0], "WE") == OK && !data->textures_paths.west)
		if (!(data->textures_paths.west = ft_strdup(path)))
			return (ERR_MALLOC);
	if (ft_strcmp(splitted[0], "S") == OK && !data->textures_paths.sprite)
		if (!(data->textures_paths.sprite = ft_strdup(path)))
			return (ERR_MALLOC);
	return (OK);
}

static int	extract_color(char *line, char **sp_splitted, t_data *data)
{
	char	**spt;

	if (!(spt = ft_split(line, ",\f\t \n\r\v")))
		return (ERR_MALLOC);
	if (ft_strcmp(sp_splitted[0], "F") == OK)
		data->color_textures.floor =
			(atoi(spt[1]) << 16) + (atoi(spt[2]) << 8) + atoi(spt[3]);
	if (ft_strcmp(sp_splitted[0], "C") == OK)
		data->color_textures.sky =
			(atoi(spt[1]) << 16) + (atoi(spt[2]) << 8) + atoi(spt[3]);
	ft_clear_splitted(spt);
	return (OK);
}

static void	extract_resolution(char **splitted, t_data *data)
{
	int		screen_size_x;
	int		screen_size_y;
	long	res_x;
	long	res_y;

	res_x = ft_atol(splitted[1]);
	res_y = ft_atol(splitted[2]);
	if (res_x > 2147483647 || ft_strlen(splitted[1]) > 10)
		data->mlx.mlx_width = 2147483647;
	else
		data->mlx.mlx_width = ft_atoi(splitted[1]);
	if (res_y > 2147483647 || ft_strlen(splitted[2]) > 10)
		data->mlx.mlx_height = 2147483647;
	else
		data->mlx.mlx_height = ft_atoi(splitted[2]);
	mlx_get_screen_size(data->mlx.mlx_id, &screen_size_x, &screen_size_y);
	if (data->mlx.mlx_width > screen_size_x)
		data->mlx.mlx_width = screen_size_x;
	if (data->mlx.mlx_height > screen_size_y)
		data->mlx.mlx_height = screen_size_y;
}

static int	extract_map(char *line, t_data *data)
{
	int		i;
	char	**tmp;

	if (!data->map)
	{
		if (!(data->map = malloc(sizeof(char *) * 1)))
			return (ERR_MALLOC);
		(data->map)[0] = NULL;
	}
	i = 0;
	while ((data->map)[i])
		i++;
	if (!(tmp = malloc(sizeof(char *) * (i + 2))))
		return (ERR_MALLOC);
	i = -1;
	while ((data->map)[++i])
		tmp[i] = (data->map)[i];
	if (!(tmp[i] = ft_strdup(line)))
		return (ERR_MALLOC);
	tmp[i + 1] = NULL;
	free(data->map);
	data->map = tmp;
	return (OK);
}

int			extract_line_content(char *line, t_file_state *file_state,
								t_data *data)
{
	char	**splitted;
	int		ret_code;

	if (!(splitted = ft_split(line, "\f\t \n\r\v")))
		return (ERR_MALLOC);
	if (!splitted[0])
	{
		ft_clear_splitted(splitted);
		return (OK);
	}
	if (file_state->is_current_line_texture)
		if ((ret_code = extract_texture(splitted, line, data)) != OK)
			return (ret_code);
	if (file_state->is_current_line_color)
		if ((ret_code = extract_color(line, splitted, data)) != OK)
			return (ret_code);
	if (file_state->is_current_line_resolution)
		extract_resolution(splitted, data);
	if (file_state->is_current_line_map)
		if ((ret_code = extract_map(line, data)) != OK)
			return (ret_code);
	ft_clear_splitted(splitted);
	return (OK);
}
