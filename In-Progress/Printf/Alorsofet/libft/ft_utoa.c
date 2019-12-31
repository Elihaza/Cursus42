/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_utoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 08:34:50 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 04:42:43 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
