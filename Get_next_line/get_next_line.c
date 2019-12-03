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

int		get_next_line(int fd, char **line)
{
	static char	*buf[1025];
	char		*stack;

	if (!line || fd < 0 || fd > 1025 || (read(fd, buf[fd], 0) < 0))
		return (-1)
	

}
