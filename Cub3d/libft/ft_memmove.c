/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
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
}
