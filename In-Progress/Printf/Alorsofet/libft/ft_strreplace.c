/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:32:17 by ellarbi           #+#    #+#             */
/*   Updated: 2020/01/14 15:32:18 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strreplace(const char *str, char *target, char *substitute)
{
	size_t		count;
	size_t		size;
	char		*replaced;
	char		*temp;

	count = 0;
	if (!str)
		return (NULL);
	if (!ft_strnstr(str, target, ft_strlen(str)) || !substitute)
		return ((char *)str);
	size = ft_strlen(str) + ft_strlen(substitute) - ft_strlen(target);
	if (!(replaced = ft_calloc(size, sizeof(char))))
		return (NULL);
	size = (int)ft_strnstr(str, target, ft_strlen(str)) - (int)str;
	ft_strncpy(replaced, (char *)str, size);
	temp = ft_strjoin(replaced, substitute);
	free(replaced);
	replaced = temp;
	return (replaced);
}
