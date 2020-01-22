/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:32:55 by ellarbi           #+#    #+#             */
/*   Updated: 2020/01/14 15:32:57 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_utoa_base(unsigned int n, char *base)
{
	char					*str;
	unsigned	int			i;

	i = ft_strbaselen(n, base);
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = 0;
	if (n == 0)
		str[0] = '0';
	while (n)
	{
		str[--i] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
	}
	return (str);
}
