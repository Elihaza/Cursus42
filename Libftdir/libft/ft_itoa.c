/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:40:56 by ellarbi           #+#    #+#             */
/*   Updated: 2019/11/08 17:40:57 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		count_n(int n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		s;
	int		len;
	char	*tab;

	s = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		s = 1;
	}
	len = count_n(n);
	if (!(tab = malloc(len + 1 + s)))
		return (NULL);
	if (s)
		tab[0] = '-';
	tab[len + s] = '\0';
	while (len)
	{
		tab[len - (s ? 0 : 1)] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (tab);
}
