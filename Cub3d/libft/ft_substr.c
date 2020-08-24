/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:37:44 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/18 13:37:45 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
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
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
