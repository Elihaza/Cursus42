/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 15:41:38 by ellarbi           #+#    #+#             */
/*   Updated: 2020/07/26 17:45:38 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "mlx.h"
#include "../cub3d.h"
#include "init.h"

static int	check_args(int argc, char **argv)
{
	int	map_path_len;

	if (argc < 2)
		return (ERR_TOO_FEW_ARGS);
	if (argc > 3)
		return (ERR_TOO_MUCH_ARGS);
	if (argc == 3 && ft_strcmp("--save", argv[2]))
		return (ERR_UK_ARG);
	map_path_len = ft_strlen(argv[1]);
	if (argv[1][map_path_len - 4] != '.' || argv[1][map_path_len - 3] != 'c' ||
		argv[1][map_path_len - 2] != 'u' || argv[1][map_path_len - 1] != 'b')
		return (ERR_NOT_CUB_MAP);
	return (OK);
}

static void	init_data(t_data *data)
{
	int	i;

	data->map = NULL;
	data->map_width = 0;
	data->map_height = 0;
	i = -1;
	while (++i < 280)
		data->keylist[i] = 0;
	data->textures_paths.north = NULL;
	data->textures_paths.south = NULL;
	data->textures_paths.east = NULL;
	data->textures_paths.west = NULL;
	data->textures_paths.sprite = NULL;
	data->mlx.north_texture.img = NULL;
	data->mlx.south_texture.img = NULL;
	data->mlx.east_texture.img = NULL;
	data->mlx.west_texture.img = NULL;
	data->mlx.sprite_texture.img = NULL;
	data->color_textures.sky = -1;
	data->color_textures.floor = -1;
	data->mlx.mlx_width = -1;
	data->mlx.mlx_window_id = NULL;
}

int			init(int argc, char **argv, t_data **data)
{
	int	ret_code;
	int	fd;

	if (!(*data = malloc(sizeof(t_data))))
		return (ERR_MALLOC);
	init_data(*data);
	if ((ret_code = check_args(argc, argv)) != OK)
		return (ret_code);
	if (!((*data)->mlx.mlx_id = mlx_init()))
		return (ERR_MLX);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (ERR_OPEN_MAP);
	if ((ret_code = read_input_file(fd, *data)) != OK)
		return (ret_code);
	close(fd);
	if ((ret_code = compute_data(*data)) != OK)
		return (ret_code);
	if ((ret_code = is_map_closed(*data)) != OK)
		return (ret_code);
	return (OK);
}
