/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:22:13 by frdescam          #+#    #+#             */
/*   Updated: 2019/10/19 22:18:00 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*original_dst;

	if (!dst && !src)
		return (NULL);
	original_dst = dst;
	while (n--)
		*((char *)dst++) = *((char *)src++);
	return (original_dst);
}
/*
**#include <string.h>
**
**int		main(void)
**{
**	write(1, "ft_memcpy\n", 10);
**	ft_memcpy(NULL, NULL, 0);
**	write(1, "memcpy\n", 7);
**	memcpy(NULL, NULL, 0);
**}
*/
