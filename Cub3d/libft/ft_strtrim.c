/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:19:23 by ellarbi           #+#    #+#             */
/*   Updated: 2019/10/17 22:55:39 by ellarbi          ###   ########.fr       */
=======
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:37:59 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/18 13:39:32 by pmouhali         ###   ########.fr       */
>>>>>>> e0eb398aa0f075849c0b55de1001e8c793dd29df
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
static unsigned int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	unsigned int	outstr_size;
	char			*outstr_start;
	char			*outstr_end;
	char			*outstr;
=======
char		*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		j;
>>>>>>> e0eb398aa0f075849c0b55de1001e8c793dd29df

	if (!s1 || !set)
		return (NULL);
	i = 0;
<<<<<<< HEAD
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	outstr_start = (char *)&s1[i];
	if ((i = ft_strlen(s1) - 1) != -1)
		while (i >= 0 && is_in_set(s1[i], set))
			i--;
	outstr_end = (char *)&s1[i];
	if (!*s1 || outstr_end == outstr_start)
		outstr_size = 2;
	else
		outstr_size = outstr_end - outstr_start + 2;
	if (!(outstr = malloc(sizeof(char) * outstr_size)))
		return (NULL);
	ft_strlcpy(outstr, outstr_start, outstr_size);
	return (outstr);
}
/*
**int					main(void)
**{
**	ft_putendl_fd(ft_strtrim("lorem ipsum dolor sit am", "oa"), 1);
**	return (0);
**}
*/
=======
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
>>>>>>> e0eb398aa0f075849c0b55de1001e8c793dd29df
