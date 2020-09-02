/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:33:00 by ellarbi           #+#    #+#             */
/*   Updated: 2020/05/10 15:08:52 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		gnl_get_full_line(t_content *content, char **first_str)
{
	if (!(*first_str = malloc(sizeof(char) * (content->line_len + 1))))
		return (-1);
	(*first_str)[content->line_len] = '\0';
	while (content->line_len)
	{
		content->line_len--;
		(*first_str)[content->line_len] = content->line[content->line_len];
	}
	free(content->line);
	if (!(content->line = malloc(sizeof(char) * BUFFER_SIZE)))
		return (-1);
	return (1);
}

static int		gnl_get_first_line(t_content *content, char **first_str, int i)
{
	int		j;
	char	*tmp;
	int		last_line_len;

	j = -1;
	if (!(*first_str = malloc(sizeof(char) * (i + 1))))
		return (-1);
	while (++j < i)
		(*first_str)[j] = content->line[j];
	(*first_str)[j] = '\0';
	if (!(tmp = malloc(sizeof(char) * (content->line_len - j - 1))))
		return (-1);
	last_line_len = content->line_len;
	content->line_len = 0;
	while (++i < last_line_len)
		tmp[content->line_len++] = content->line[i];
	free(content->line);
	content->line = tmp;
	return (1);
}

static int		gnl_get_first_str(t_content *content, char **first_str)
{
	unsigned int i;

	*first_str = NULL;
	i = 0;
	while (i < content->line_len && content->line[i] != '\n')
		i++;
	if (i == content->line_len && content->read_status != BUFFER_SIZE &&
			content->line_len != 0)
	{
		if (!(gnl_get_full_line(content, first_str)))
			return (-1);
		return (0);
	}
	else if (i < content->line_len)
	{
		if (!(gnl_get_first_line(content, first_str, i)))
			return (-1);
	}
	return (1);
}

static int		gnl_get_str(t_content *content, char **line)
{
	char	buf[BUFFER_SIZE];
	char	*tmp;
	char	*first_str;
	int		status;

	if ((status = gnl_get_first_str(content, &first_str)) == -1)
		return (-1);
	while (!first_str && content->read_status != 0)
	{
		if ((content->read_status = read(content->fd, buf, BUFFER_SIZE)) == -1)
			return (-1);
		if (!(tmp = gnl_strjoin(content->line, buf, content->line_len,
						BUFFER_SIZE)))
			return (-1);
		free(content->line);
		content->line = tmp;
		content->line_len += content->read_status;
		if ((status = gnl_get_first_str(content, &first_str)) == -1)
			return (-1);
	}
	*line = first_str;
	if (!content->read_status)
		return (0);
	return (status);
}

int				get_next_line(int fd, char **line)
{
	static t_hold	*lst = NULL;
	t_hold			*elem;
	int				status;

	if (fd < 0 || !line)
		return (-1);
	if (!(elem = gnl_get_elem_by_fd(lst, fd)))
		if (!(elem = gnl_lst_add_new(&lst, fd)))
			return (gnl_lstclear(lst));
	if (!((status = gnl_get_str(elem->content, line))))
		gnl_lstdelone(elem, &lst);
	if (!*line)
	{
		if (!(*line = malloc(sizeof(char) * 1)))
			return (gnl_lstclear(lst));
		**line = '\0';
	}
	return (status);
}
/*
**#include <stdio.h>
**#include <fcntl.h>
**
**int		main(int argc, char **argv)
**{
**	int		fd[argc];
**	int		ret[argc];
**	char	*str;
**	int		are_all_files_read;
**	int		i;
**
**	are_all_files_read = 0;
**	i = 0;
**	if (argc == 1)
**	{
**		while (ret[0])
**		{
**			fd[0] = open("/dev/stdin", O_RDONLY);
**			ret[0] = get_next_line(fd[0], &str);
**			printf("%d-%s\n", ret[0], str);
**			free(str);
**		}
**	}
**	while (i < argc - 1)
**	{
**		fd[i] = open(argv[i + 1], O_RDONLY);
**		i++;
**	}
**	i = 0;
**	while (!are_all_files_read)
**	{
**		while (i < argc - 1)
**		{
**			ret[i] = get_next_line(fd[i], &str);
**			printf("%d-%s\n", ret[i], str);
**			free(str);
**			i++;
**		}
**		are_all_files_read = 1;
**		while (i)
**		{
**			i--;
**			if (ret[i])
**				are_all_files_read = 0;
**		}
**	}
**	while (1)
**		;
**	return (0);
**}
*/
