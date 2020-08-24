NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRCS =	ft_memmove.c \
		ft_strlen.c \
		ft_isalpha.c \
		ft_strrchr.c \
		ft_strcmp.c \
		ft_atoi.c \
		ft_strndup.c \
		ft_substr.c \
		ft_strtrim.c \
		ft_strctrim.c \
		get_next_line.c \
		ft_index.c \
		ft_bzero.c \
		free_tda.c \
		new_tda.c \

OBJS = $(SRCS:.c=.o)

HEADER = libft.h


$(NAME):
		gcc $(FLAGS) -c $(SRCS) -I./ $(HEADER)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
