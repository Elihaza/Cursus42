/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:50:49 by ellarbi           #+#    #+#             */
/*   Updated: 2019/11/04 14:50:51 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*strd;
	const char	*strs;

	if (dst == 0 && src == 0)
		return (0);
	strd = (char *)dst;
	strs = (const char*)src;
	while (n--)
		*strd++ = *strs++;
	return (dst);
}
