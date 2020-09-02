/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_stars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 23:04:30 by ellarbi           #+#    #+#             */
/*   Updated: 2019/11/18 23:06:57 by ellarbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		replace_star(t_block *block, int nb_stars, int i)
{
	char	*tmp;
	char	*tmp2;
	char	*star;

	if (!(tmp = ft_strndup(block->to_convert, i)))
		return (-1);
	if (!(star = ft_itoa(*(block->star[nb_stars]))))
		return (-1);
	if (!(tmp2 = ft_strjoin(tmp, star)))
		return (-1);
	free(tmp);
	free(star);
	if (!(tmp = ft_strjoin(tmp2, &block->to_convert[i + 1])))
		return (-1);
	free(tmp2);
	free(block->to_convert);
	block->to_convert = tmp;
	return (1);
}

int				replace_stars(t_block *block)
{
	int		nb_stars;
	int		i;

	nb_stars = 0;
	i = 0;
	while (block->to_convert[i])
	{
		if (block->to_convert[i] == '*')
		{
			if ((replace_star(block, nb_stars, i)) == -1)
				return (-1);
			nb_stars++;
		}
		i++;
	}
	return (1);
}
