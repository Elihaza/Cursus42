/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strbaselen.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/21 23:05:28 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 23:07:20 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
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
