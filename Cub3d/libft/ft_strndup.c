/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<< HEAD
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 23:35:11 by ellarbi           #+#    #+#             */
/*   Updated: 2019/11/11 23:41:57 by ellarbi          ###   ########.fr       */
=======
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:02:19 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/18 13:42:06 by pmouhali         ###   ########.fr       */
>>>>>>> e0eb398aa0f075849c0b55de1001e8c793dd29df
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD
char	*ft_strndup(const char *s1, size_t n)
{
	char	*dest;
	int		s1_len;
	int		i;

	s1_len = 0;
	while (s1[s1_len] && s1_len < (int)n)
		s1_len++;
	if (!(dest = (char *)malloc(sizeof(char) * (s1_len + 1))))
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
**int		main(void)
**{
**	printf("%s\n", ft_strndup("Hello world!", 5));
**	return (0);
**}
*/
=======
char	*ft_strndup(const char *s, unsigned int n)
{
	unsigned int	i;
	char			*new;

	i = 0;
	while (s[i] && i < n)
		i++;
	if ((new = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (*s && i < n)
	{
		new[i] = *s;
		i++;
		s++;
	}
	new[i] = '\0';
	return (new);
}
>>>>>>> e0eb398aa0f075849c0b55de1001e8c793dd29df
