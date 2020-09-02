/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:07:44 by ellarbi           #+#    #+#             */
/*   Updated: 2019/10/19 11:57:33 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*last_occurence;

	last_occurence = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			last_occurence = (char *)&s[i];
		i++;
	}
	if ((char)c == s[i])
		return ((char *)&s[i]);
	return (last_occurence);
=======
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:42:52 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/18 13:43:31 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char *pointer;

	pointer = (void*)0;
	while (*s != '\0')
	{
		if (*s == c)
			pointer = (char*)s;
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (pointer);
>>>>>>> e0eb398aa0f075849c0b55de1001e8c793dd29df
}
