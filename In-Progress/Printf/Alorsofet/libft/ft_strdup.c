/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: amonteli <amonteli@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 21:25:14 by amonteli     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 01:40:52 by amonteli    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		count;
	char	*tab;

	count = 0;
	while (s[count])
		count++;
	if (!(tab = (char *)malloc((count + 1) * sizeof(char))))
		return (NULL);
	count = -1;
	while (s[++count])
		tab[count] = s[count];
	tab[count] = '\0';
	return (tab);
}
