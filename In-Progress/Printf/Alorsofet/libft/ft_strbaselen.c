/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbaselen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:31:29 by ellarbi           #+#    #+#             */
/*   Updated: 2020/01/14 15:31:32 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long		ft_strbaselen(unsigned long long n, char *base)
{
	long unsigned int	len;

	len = 1;
	while (n /= ft_strlen(base))
		len++;
	return (len);
}
