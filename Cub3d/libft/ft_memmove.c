/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:34:48 by ellarbi           #+#    #+#             */
/*   Updated: 2019/10/19 22:17:08 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len > 0)
		{
			((char *)dst)[len - 1] = ((char *)src)[len - 1];
			len--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dst);
=======
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:16:41 by pmouhali          #+#    #+#             */
/*   Updated: 2019/11/15 15:18:38 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void			*ft_memmove(void *dest, const void *src, unsigned long n)
{
	unsigned long		i;
	unsigned char		*cdest;
	const unsigned char	*csrc;

	if ((!dest && !src) || dest == src)
		return (dest);
	cdest = dest;
	csrc = src;
	i = 0;
	if (dest <= src)
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	else
		while (n > 0)
		{
			cdest[n - 1] = csrc[n - 1];
			n--;
		}
	return (dest);
>>>>>>> e0eb398aa0f075849c0b55de1001e8c793dd29df
}
