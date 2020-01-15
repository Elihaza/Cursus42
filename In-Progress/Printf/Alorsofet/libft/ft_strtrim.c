/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:40:48 by ellarbi           #+#    #+#             */
/*   Updated: 2019/11/08 17:40:49 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t		can_trim(char c, char const *set)
{
	size_t		occur;

	occur = -1;
	while (set[++occur])
		if (set[occur] == c)
			return (1);
	return (0);
}

static	size_t		count_char(char const *s1, char const *set)
{
	size_t		occur;
	size_t		len;

	occur = 0;
	len = ft_strlen(s1);
	while (can_trim(s1[len - occur - 1], set))
		occur++;
	return (len - occur);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	size_t		occur;
	size_t		len;
	char		*str;

	occur = 0;
	len = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	while (can_trim(s1[occur], set))
		occur++;
	if (occur == (size_t)ft_strlen(s1))
		return (ft_strdup(""));
	len = count_char(s1 + occur, set) + 1;
	if (!(str = malloc(len)))
		return (NULL);
	ft_strlcpy(str, s1 + occur, len);
	return (str);
}
