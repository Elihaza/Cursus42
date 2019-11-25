/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:19:51 by ellarbi           #+#    #+#             */
/*   Updated: 2019/11/25 11:19:52 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
// # define BUFFER_SIZE 32

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const	char *s);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strsub(char const *s, unsigned int start, size_t len);

#endif
