/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 21:47:38 by frdescam          #+#    #+#             */
/*   Updated: 2019/11/13 23:12:38 by frdescam         ###   ########.fr       */
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

static int		ft_malloc(char **nb_c, int *sign, long *nb_l, int *nb)
{
	if (!(*nb_c = (char *)malloc(sizeof(char) * 40)))
		return (0);
	*sign = 1;
	if (*nb == 0)
		(*nb_c)[0] = '0';
	if (*nb < 0)
	{
		*nb_l = *nb;
		*nb_l *= -1;
		*sign = -1;
	}
	else
		*nb_l = *nb;
	return (1);
}

char			*ft_itoa_base(int nb, const char *base)
{
	long	nb_l;
	char	*nb_c;
	int		base_divider;
	int		i;
	int		sign;

	if (!(ft_malloc(&nb_c, &sign, &nb_l, &nb)))
		return (0);
	base_divider = ft_strlen(base);
	if (nb_c[0] == '0')
		i = 1;
	else
		i = 0;
	while (nb_l > 0)
	{
		nb_c[i++] = base[nb_l % base_divider];
		nb_l /= base_divider;
	}
	if (sign == -1)
		nb_c[i++] = '-';
	nb_c[i] = '\0';
	return (ft_strrev(nb_c));
}

static int		ft_mallocl(char **nb_c, int *sign, unsigned long *nb)
{
	if (!(*nb_c = (char *)malloc(sizeof(char) * 40)))
		return (0);
	*sign = 1;
	if (*nb == 0)
		(*nb_c)[0] = '0';
	return (1);
}

char			*ft_ltoa_base(unsigned long nb, const char *base)
{
	char	*nb_c;
	int		base_divider;
	int		i;
	int		sign;

	if (!(ft_mallocl(&nb_c, &sign, &nb)))
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
	if (sign == -1)
		nb_c[i++] = '-';
	nb_c[i] = '\0';
	return (ft_strrev(nb_c));
}
