/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 23:01:57 by ellarbi           #+#    #+#             */
/*   Updated: 2020/05/10 15:04:21 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# define BUFFER_SIZE 10

typedef struct			s_content
{
	char	*line;
	size_t	line_len;
	int		fd;
	int		read_status;
}						t_content;

typedef struct			s_hold
{
	t_content		*content;
	struct s_hold	*next;
}						t_hold;

int						get_next_line(int fd, char **line);
void					gnl_lstdelone(t_hold *elem, t_hold **lst);
t_hold					*gnl_get_elem_by_fd(t_hold *lst, int fd);
int						gnl_lstclear(t_hold *lst);
t_hold					*gnl_lst_add_new(t_hold **lst, int fd);
char					*gnl_strjoin(char const *s1, char const *s2,
							size_t s1_len, size_t s2_len);

#endif
