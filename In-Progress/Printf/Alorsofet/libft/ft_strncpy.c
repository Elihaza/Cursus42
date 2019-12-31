/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/28 17:14:11 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/23 06:27:27 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (src[count] && n > 0)
	{
		dest[count] = src[count];
		count++;
		n--;
	}
	while (n > 0)
	{
		dest[count] = '\0';
		count++;
		n--;
	}
	free(src);
	return (dest);
}
