/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:32:33 by ellarbi           #+#    #+#             */
/*   Updated: 2020/01/14 15:32:35 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_ulltoa_base(unsigned long long n, char *base)
{
	char					*str;
	unsigned long long		i;

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
