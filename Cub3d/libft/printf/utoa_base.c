/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:39:56 by frdescam          #+#    #+#             */
/*   Updated: 2019/12/05 11:48:10 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_strrev(char *str)
{
	int		size;
	int		i;
	char	tmp;

	size = ft_strlen(str);
	size--;
	i = 0;
	while (i < size)
	{
		tmp = str[i];
		str[i] = str[size];
		str[size] = tmp;
		i++;
		size--;
	}
	return (str);
}

static int		ft_malloc(char **nb_c, unsigned int *nb)
{
	if (!(*nb_c = (char *)malloc(sizeof(char) * 40)))
		return (0);
	if (*nb == 0)
		(*nb_c)[0] = '0';
	return (1);
}

char			*utoa_base(unsigned int nb, const char *base)
{
	char	*nb_c;
	int		base_divider;
	int		i;

	if (!(ft_malloc(&nb_c, &nb)))
		return (0);
	base_divider = ft_strlen(base);
	if (nb_c[0] == '0')
		i = 1;
	else
		i = 0;
	while (nb > 0)
	{
		nb_c[i++] = base[nb % base_divider];
		nb /= base_divider;
	}
	nb_c[i] = '\0';
	return (ft_strrev(nb_c));
}
