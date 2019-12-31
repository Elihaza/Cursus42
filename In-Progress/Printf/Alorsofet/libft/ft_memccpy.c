/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/12 17:16:51 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/31 16:59:38 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			count;
	unsigned char	*source;
	unsigned char	*d;

	count = 0;
	source = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!src && !dest)
		return (NULL);
	while (count < n)
	{
		d[count] = source[count];
		if (source[count] == (unsigned char)c)
			return (d + count + 1);
		count++;
	}
	return (0);
}
