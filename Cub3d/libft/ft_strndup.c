/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:02:19 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/18 13:42:06 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, unsigned int n)
{
	unsigned int	i;
	char			*new;

	i = 0;
	while (s[i] && i < n)
		i++;
	if ((new = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*s && i < n)
	{
		new[i] = *s;
		i++;
		s++;
	}
	new[i] = '\0';
	return (new);
}
