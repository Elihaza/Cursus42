NAME = libbitmapfile.a

FLAGS = -Wall -Wextra -Werror

SRCS =	dint4cpy.c \
	write_bmpfileheader.c \
	write_bmpinfoheader.c \
	write_pixeldata.c \
	create_bmpfile.c \

OBJS = $(SRCS:.c=.o)

HEADER = bitmapfile.h


$(NAME): $(OBJS)
	gcc $(FLAGS) -c $(SRCS) -I./ $(HEADER)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all
