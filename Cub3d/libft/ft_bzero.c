/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:02:30 by ellarbi           #+#    #+#             */
/*   Updated: 2019/10/19 11:46:42 by ellarbi          ###   ########.fr       */
=======
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:12:27 by pmouhali          #+#    #+#             */
/*   Updated: 2019/11/04 14:12:39 by pmouhali         ###   ########.fr       */
>>>>>>> e0eb398aa0f075849c0b55de1001e8c793dd29df
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
<<<<<<< HEAD
	unsigned int	i;
	char			*s_c;

	s_c = (char *)s;
	i = 0;
	while (i < n)
	{
		*(s_c + i) = 0;
		i++;
=======
	unsigned char *a;

	a = s;
	while (n > 0)
	{
		*a = 0;
		a++;
		n--;
>>>>>>> e0eb398aa0f075849c0b55de1001e8c793dd29df
	}
}
