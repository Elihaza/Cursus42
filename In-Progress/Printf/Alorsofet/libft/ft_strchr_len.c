/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:31:45 by ellarbi           #+#    #+#             */
/*   Updated: 2020/01/14 15:31:47 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strchr_len(const char *s, int c)
{
	int		count;

	count = -1;
	while (s[++count])
		if (s[count] == c)
			return (count);
	if (s[count] == c)
		return (count);
	return (0);
}
