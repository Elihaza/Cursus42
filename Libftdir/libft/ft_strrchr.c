/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:05:07 by ellarbi           #+#    #+#             */
/*   Updated: 2019/11/05 17:05:08 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_strchrtest(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return (char *)s;
}

char			*ft_strrchr(const char *s, int c)
{
	const char *found;
	const char *ptr;

	c = (unsigned char)c;
	if (c == '\0')
		return (ft_strchrtest(s, '\0'));
	found = 0;
	while ((ptr = ft_strchrtest(s, c)) != 0)
	{
		found = ptr;
		s = ptr + 1;
	}
	return ((char *)found);
}
