# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/21 16:00:31 by ellarbi           #+#    #+#              #
#    Updated: 2020/05/25 19:09:56 by ellarbi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c \
ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putendl_fd.c \
ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memccpy.c ft_putnbr_fd.c ft_strlen.c \
ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strcmp.c ft_strmapi.c \
ft_isalnum.c ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c \
ft_strchr.c ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c \
ft_strndup.c \
\
printf/ft_printf.c printf/parsing.c printf/get_args.c printf/retrieve_args.c \
printf/convert.c printf/itoa_base.c printf/convert_func1.c \
printf/convert_func2.c printf/apply_modifiers.c printf/replace_stars.c \
printf/apply_width.c printf/apply_precision.c printf/utoa.c printf/utoa_base.c \
printf/apply_width_to_int.c printf/is_type.c \
\
lst/ft_lstadd_back.c lst/ft_lstadd_front.c lst/ft_lstclear.c \
lst/ft_lstdelone.c lst/ft_lstiter.c lst/ft_lstlast.c lst/ft_lstmap.c \
lst/ft_lstnew.c lst/ft_lstsize.c lst/ft_lstcat.c lst/ft_lstsort.c \
lst/ft_lstsearch.c \
\
gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}

CC		= cc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror -g3

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY : all clean fclean re
