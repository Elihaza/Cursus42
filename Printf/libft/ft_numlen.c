/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:31:12 by ellarbi           #+#    #+#             */
/*   Updated: 2020/01/14 15:31:15 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_numlen(int n)
{
	long long int	count;
	long long int	number;

	number = (long long int)n;
	count = 1;
	if (number < 0)
		number *= -1;
	while (number > 9)
	{
		number /= 10;
		count++;
	}
	return (count);
}
