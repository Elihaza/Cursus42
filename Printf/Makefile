# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellarbi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 15:35:59 by ellarbi           #+#    #+#              #
#    Updated: 2020/01/14 15:36:03 by ellarbi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=		libftprintf.a

HEADERS		=		includes/ft_printf.h

LIBFT_INC	=		libft/libft.h

LIBFT_SRCS	=		ft_atoi.c				\
					ft_bzero.c				\
					ft_isalnum.c			\
					ft_isalpha.c			\
					ft_isascii.c			\
					ft_isdigit.c			\
					ft_isprint.c			\
					ft_memcpy.c				\
					ft_memset.c				\
					ft_strchr.c				\
					ft_strrchr.c			\
					ft_strlen.c				\
					ft_strncmp.c			\
					ft_strnstr.c			\
					ft_tolower.c			\
					ft_toupper.c			\
					ft_memccpy.c			\
					ft_memmove.c			\
					ft_memchr.c				\
					ft_memcmp.c				\
					ft_calloc.c				\
					ft_strdup.c				\
					ft_strlcpy.c			\
					ft_strlcat.c			\
					ft_substr.c				\
					ft_strjoin.c			\
					ft_strtrim.c			\
					ft_split.c				\
					ft_itoa.c				\
					ft_strmapi.c			\
					ft_putchar_fd.c			\
					ft_putstr_fd.c			\
					ft_putendl_fd.c			\
					ft_putnbr_fd.c			\
					ft_lstnew.c				\
					ft_lstadd_front.c		\
					ft_lstsize.c			\
					ft_lstlast.c			\
					ft_lstadd_back.c		\
					ft_lstdelone.c			\
					ft_lstclear.c			\
					ft_lstiter.c			\
					ft_lstmap.c				\
					ft_strncpy.c			\
					ft_strchr_len.c			\
					ft_lltoa_base.c			\
					ft_numlen.c				\
					ft_ltoa.c				\
					ft_ulltoa_base.c		\
					ft_strbaselen.c			\
					ft_utoa.c				\
					ft_utoa_base.c			\
					ft_strreplace.c			\

SRCS 		=		ft_printf.c				\
					pf_parser.c				\
					pf_content_manager.c	\
					pf_converter.c 			\
					pf_utils.c				\
					pf_int_converter.c		\
					bonus/pf_bonus.c		\

FLAGS 		= 		-Wall -Wextra -Werror

OBJS		= 		$(addprefix srcs/, $(SRCS:.c=.o)) $(addprefix libft/, $(LIBFT_SRCS:.c=.o))

LIB 		= 		libft/libft.a

all			: 		$(NAME)

$(NAME)		: $(OBJS)
		@make -C libft
		@cp libft/libft.a $(NAME)
		@ar rcs $(NAME) $(OBJS) $(LIB)
		@echo "\033[90m[\033[32mft_printf\033[90m]\033[32m Successfully compiled ft_printf.\033[0m"

%.o: %.c $(HEADERS) libft/libft.h
		@gcc -I $(HEADERS) -I $(LIBFT_INC) -o $@ -c $< $(FLAGS)
		@echo "\033[34m█\c\033[0m"

bonus		:		$(NAME)

clean		:
		@/bin/rm -f $(OBJS)
		@make clean -C libft
		@echo "\033[90m[\033[91mft_printf\033[90m]\033[31m Deleted *.o\033[0m"

fclean		:		clean
		@/bin/rm -f $(NAME)
		@make fclean -C libft
		@echo "\033[90m[\033[91mft_printf\033[90m]\033[31m Deleted $(NAME)\033[0m"

re			:		fclean all

norme		:
		@norminette srcs/*.c srcs/bonus/*.c includes/*.h libft/*.c libft/*.h
