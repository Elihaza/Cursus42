/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmouhali <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:48:01 by pmouhali          #+#    #+#             */
/*   Updated: 2020/01/18 13:49:26 by pmouhali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define BUFFER_SIZE 50

# define LIBFTTEST "libft"

int		ft_strlen(const char *str);
void	ft_bzero(void *s, size_t n);
int		ft_index(char const *s, char c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_isalpha(int c);
int		ft_atoi(const char *str);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	free_tda(void **two_dimensional_array, int first_dimension_length);
char	*ft_strndup(const char *s, unsigned int n);
char	*ft_strctrim(const char *s, int c);
void	*ft_memmove(void *dest, const void *src, unsigned long n);
int		get_next_line(int fd, char **line);
void	**new_tda(int size, int height, int width);

#endif
