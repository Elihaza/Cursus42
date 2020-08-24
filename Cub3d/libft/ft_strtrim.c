/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:37:59 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/18 13:39:32 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] != '\0' && ft_index(set, s1[i]) != -1)
		i++;
	j = i;
	while (s1[j] != '\0')
		j++;
	if ((j = j > 0 ? j - 1 : 0) > 0)
		while (j > 0 && ft_index(set, s1[j]) != -1)
			j--;
	new = ft_substr(s1, i, (j - i) + 1);
	return (new);
}
