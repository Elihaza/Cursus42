/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:19:08 by ellarbi           #+#    #+#             */
/*   Updated: 2019/11/25 11:19:12 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		error(int fd, char **str, char **line)
{
	if (fd == -1 || line == NULL)
		return (-1);
	if (!*str)
	{
		if (!(*str = (char*)malloc((BUFFER_SIZE + 1))))
			return (-1);
	}
	return (0);
}

char		*readline(char *str, int fd)
{
	char	buff[BUFFER_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int				get_next_line(int fd, char **line)
{
	int			i;
	static char	*str;

	if (error(fd, &str, line) == -1)
		return (-1);
	if (*str)
		ft_strcpy(*line, str);
	str = readline(str, fd);
	i = 0;
	if (str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (i == 0)
			(*line) = ft_strdup("");
		else
		{
			(*line) = ft_strsub(str, 0, i);
			str = &str[i + 1];
		}
		return (1);
	}
	else
		(*line) = ft_strdup("");
	return (0);
}
