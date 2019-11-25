/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:13:19 by ellarbi           #+#    #+#             */
/*   Updated: 2019/08/31 18:05:36 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && (ft_strlen(haystack) >= ft_strlen(needle)))
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i] == needle[j])
			{
				if (needle[j + 1] == '\0')
					return ((char *)&haystack[i - j]);
				i++;
				j++;
			}
			i = i - j;
		}
		j = 0;
		i++;
	}
	return (0);
}
