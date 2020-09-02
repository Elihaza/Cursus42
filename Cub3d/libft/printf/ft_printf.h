/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frdescam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 22:24:05 by frdescam          #+#    #+#             */
/*   Updated: 2020/01/31 14:14:19 by frdescam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft.h"

typedef struct	s_block
{
	char		*to_convert;
	char		type;
	void		*value;
	int			*star[2];
	char		*converted;
}				t_block;
int				parsing(const char *str, t_list **lst);
int				retrieve_int(void **out, va_list args);
int				retrieve_char(void **out, va_list args);
int				retrieve_ptr(void **out, va_list args);
int				retrieve_uint(void **out, va_list args);
int				get_args(t_list *lst, va_list args);
int				convert(t_list *lst);
int				is_type(char c);
char			*ft_ltoa_base(unsigned long nb, const char *base);
char			*ft_itoa_base(int nb, const char *base);
char			*utoa(unsigned int n);
int				convert_int(t_block *block);
int				convert_uint(t_block *block);
int				convert_char(t_block *block);
int				convert_str(t_block *block);
int				convert_hex(t_block *block);
int				convert_uphex(t_block *block);
int				convert_ptr(t_block *block);
int				convert_mod(t_block *block);
int				apply_modifiers(t_list *lst);
int				replace_stars(t_block *block);
int				apply_width(t_block *block, int is_minus_flag,
					int is_zero_flag);
int				apply_precision(t_block *block);
char			*utoa_base(unsigned int nb, const char *base);
int				apply_width_to_int(t_block *block, int width, int is_minus_flag,
					int is_zero_flag);

#endif
