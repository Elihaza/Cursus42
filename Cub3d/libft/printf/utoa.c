/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:14:48 by ellarbi           #+#    #+#             */
/*   Updated: 2019/12/04 21:27:02 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	get_nb_digit(unsigned int n)
{
	unsigned int	nb_digit;

	if (n == 0)
		return (1);
	nb_digit = 0;
	while (n > 0)
	{
		n /= 10;
		nb_digit++;
	}
	return (nb_digit);
}

static void			convert_nb(char *outstr, unsigned int n,
		unsigned int nb_digit)
{
	outstr[nb_digit] = '\0';
	outstr[--nb_digit] = n % 10 + '0';
	n /= 10;
	while (n > 0)
	{
		outstr[--nb_digit] = n % 10 + '0';
		n /= 10;
	}
}

char				*utoa(unsigned int n)
{
	char			*outstr;
	unsigned int	nb_digit;

	nb_digit = get_nb_digit(n);
	if (!(outstr = malloc(sizeof(char) * nb_digit + 1)))
		return (NULL);
	convert_nb(outstr, n, nb_digit);
	return (outstr);
}
