/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:34:29 by ellarbi           #+#    #+#             */
/*   Updated: 2019/11/08 17:34:31 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		occur_words(char const *s, char c)
{
	int i;
	int words;
	int occur;

	i = 0;
	words = 0;
	occur = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c && s[i])
			occur = 1;
		if (s[i] == c)
		{
			while (s[i] == c && s[i])
				i++;
			if (s[i])
				words++;
		}
		else
			i++;
	}
	return (words + occur);
}

static	char	*alloc_word(char const *s, char c)
{
	int		size;
	char	*str;

	size = 0;
	str = 0;
	while (s[size] && s[size] != c)
		size++;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_strlcpy(str, s, size + 1);
	return (str);
}

char			**ft_split(char const *s, char c)
{
	int		occur;
	int		words;
	char	**str;

	occur = -1;
	if (!s)
		return (NULL);
	words = occur_words(s, c);
	if (!(str = malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (++occur < words)
	{
		while (s[0] == c)
			s++;
		if (!(str[occur] = alloc_word(s, c)))
		{
			while (occur > 0)
				free(str[occur--]);
			free(str);
			return (NULL);
		}
		s += ft_strlen(str[occur]);
	}
	str[occur] = 0;
	return (str);
}
