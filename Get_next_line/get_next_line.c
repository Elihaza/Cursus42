/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:19:08 by ellarbi           #+#    #+#             */
/*   Updated: 2019/12/02 22:52:07 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	int		count;
	char	*tab;

	count = 0;
	if (!s)
		return (NULL);
	while (s[count])
		count++;
	if (!(tab = (char *)malloc((count + 1) * sizeof(char))))
		return (NULL);
	count = -1;
	while (s[++count])
		tab[count] = s[count];
	tab[count] = '\0';
	return (tab);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	count;
	size_t	size;
	char	*tab;

	count = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	if (!(tab = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (count < len)
	{
		tab[count] = s[start + count];
		count++;
	}
	tab[count] = '\0';
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2, int action)
{
	size_t	count;
	size_t	s1_size;
	char	*tab;

	count = -1;
	s1_size = ft_strlen(s1);
	if (!(tab = (char *)malloc((s1_size + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	if (s1)
		while (s1[++count])
			tab[count] = s1[count];
	count = -1;
	if (s2)
		while (s2[++count])
			tab[s1_size + count] = s2[count];
	tab[s1_size + count] = '\0';
	if (action && s1)
		free(s1);
	return (tab);
}

int		ft_cut_buffer(char **line, t_gnl *current, t_gnl **first)
{
	int		size;
	char	*temp;
	t_gnl	*linked;

	linked = *first;
	if (!ft_strchr(current->content, '\n'))
	{
		*line = ft_strdup(current->content);
		if (linked != current)
		{
			while (linked->next && linked->next->fd != current->fd)
				linked = linked->next;
			linked->next = current->next;
		}
		free(current->content);
		free(current);
		return (linked == current ? (int)(*first = NULL) : 0);
	}
	size = (int)(ft_strchr(current->content, '\n') - current->content);
	*line = ft_substr(current->content, 0, size);
	temp = ft_strdup(current->content + size + 1);
	free(current->content);
	current->content = temp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static t_gnl	*lst;
	t_gnl			*current;
	char			buffer[BUFFER_SIZE + 1];
	int				readed;

	readed = 0;
	if (!line || BUFFER_SIZE < 1 || read(fd, buffer, 0) < 0)
		return (-1);
	if (!lst && !(lst = ft_create_list(fd)))
		return (-1);
	if (!(current = ft_lstchr(lst, fd)) &&
		!(current = ft_lstadd(&lst, ft_create_list(fd))))
		return (-1);
	while (!ft_strchr(current->content, '\n')
		&& (readed = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[readed] = '\0';
		current->content = ft_strjoin(current->content, buffer, 1);
	}
	return (ft_cut_buffer(line, current, &lst));
}
