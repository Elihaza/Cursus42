/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
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
}
