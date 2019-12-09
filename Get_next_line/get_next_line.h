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

# include <stdlib.h>
# include <unistd.h>

typedef	struct		s_gnl
{
	int				fd;
	char			*content;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s);
char				*ft_strjoin(char *s1, char *s2, int action);
char				*ft_strchr(const char *s, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);

int					ft_cut_buffer(char **line, t_gnl *current, t_gnl **first);
char				*ft_strdup(char *s);
t_gnl				*ft_create_list(int fd);
t_gnl				*ft_lstchr(t_gnl *list, int fd);
t_gnl				*ft_lstadd(t_gnl **alst, t_gnl *new);

#endif