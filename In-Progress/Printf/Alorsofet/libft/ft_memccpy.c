/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:57:09 by ellarbi           #+#    #+#             */
/*   Updated: 2019/11/04 14:57:12 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	const char		*source;
	char			*dest;
	char			*ptr;

	dest = (char *)dst;
	source = (const char *)src;
	i = 0;
	ptr = 0;
	while (i < n && ptr == 0)
	{
		dest[i] = source[i];
		if (source[i] == ((char)c))
			ptr = dest + i + 1;
		i++;
	}
	return (ptr);
}
