/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ulltoa_base.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 04:01:50 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 22:41:31 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
