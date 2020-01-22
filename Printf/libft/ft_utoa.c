/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:32:44 by ellarbi           #+#    #+#             */
/*   Updated: 2020/01/14 15:32:45 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_utoa(unsigned int n)
{
	int		size;
	char	*tab;

	size = ft_numlen(n);
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	tab[size] = '\0';
	while (size)
	{
		tab[size - 1] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	return (tab);
}
