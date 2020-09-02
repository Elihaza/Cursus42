/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:01:35 by ellarbi           #+#    #+#             */
/*   Updated: 2019/10/15 23:25:38 by ellarbi          ###   ########.fr       */
=======
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:37:44 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/18 13:37:45 by pmouhali         ###   ########.fr       */
>>>>>>> e0eb398aa0f075849c0b55de1001e8c793dd29df
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
<<<<<<< HEAD
	unsigned int	i;
	unsigned int	s_len;
	char			*substr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
	{
		if (!(substr = malloc(sizeof(char) * 1)))
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (!(substr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
=======
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	len = (int)start > ft_strlen(s) ? 0 : len;
	i = 0;
	while (i < len && s[i + start] != '\0')
		i++;
	if ((substr = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[i + start] != '\0')
	{
		substr[i] = s[i + start];
>>>>>>> e0eb398aa0f075849c0b55de1001e8c793dd29df
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
