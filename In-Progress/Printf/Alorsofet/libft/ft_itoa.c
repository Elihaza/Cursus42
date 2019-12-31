/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 17:14:13 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 17:29:46 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	int		size;
	int		neg;
	char	*tab;

	size = ft_numlen(n);
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = -n;
		neg = 1;
	}
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1 + neg))))
		return (NULL);
	if (neg)
		tab[0] = '-';
	tab[size + neg] = '\0';
	while (size)
	{
		tab[size - (neg ? 0 : 1)] = n % 10 + '0';
		n = n / 10;
		size--;
	}
	return (tab);
}
