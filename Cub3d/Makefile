# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ellarbi  <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/08 17:53:33 by ellarbi           #+#    #+#              #
#    Updated: 2020/07/30 18:17:25 by ellarbi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SUFFIXES:
.SUFFIXES: .c .o

SHELL		= /bin/sh

NAME		= Cub3D

SRCS		= ./srcs/raycasting_engine/raycasting_engine.c \
			  ./srcs/raycasting_engine/raycasting_engine_x.c \
			  ./srcs/raycasting_engine/raycasting_engine_y.c \
			  ./srcs/raycasting_engine/raycasting_engine_utils.c \
			  ./srcs/player_moves/move_player.c ./srcs/player_moves/get_move.c \
			  ./srcs/raycasting_engine/handle_sprite.c \
			  ./srcs/raycasting_engine/handle_sprite2.c \
			  ./srcs/raycasting_engine/handle_sprite3.c \
			  ./srcs/errors/errors.c ./srcs/init/init.c \
			  ./srcs/init/read_input_file.c ./srcs/init/compute_data.c \
			  ./srcs/init/check_line_validity.c \
			  ./srcs/init/check_line_validity_utils.c \
			  ./srcs/init/extract_line_content.c ./srcs/init/init_helper.c \
			  ./srcs/exit_program/exit_program.c \
			  ./srcs/mlx_mode/cub3d_mlx.c ./srcs/mlx_mode/draw_mlx.c \
			  ./srcs/mlx_mode/handle_events.c ./srcs/mlx_mode/build_color_px.c \
			  ./srcs/mlx_mode/handle_sprite_drawing.c \
			  ./srcs/mlx_mode/bmp/bmp.c ./srcs/mlx_mode/build_image.c

OBJS		= ${SRCS:.c=.o}

CC			= cc
RM			= rm -f

MLX_FLAGS	= -Lmlx/ -lmlx -framework OpenGL -framework AppKit
UNAME_S		:= $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    MLX_FLAGS	= -Lmlx/ -lmlx -lXext -lX11 -lbsd
    DEFINES		= -D LINUX=1 -D MAC=0
endif
ifeq ($(UNAME_S), Darwin)
    MLX_FLAGS	= -Lmlx/ -lmlx -framework OpenGL -framework AppKit
    DEFINES		= -D MAC=1 -D LINUX=0
endif

MATH_FLAGS	= -lm

LIBFT_FLAGS	= -Llibft -lft

CFLAGS		= -Wall -Wextra -Werror -g3

INCLUDES	= -I mlx -I libft

all:	${NAME}

.c.o:
		${CC} ${INCLUDES} ${DEFINES} ${CFLAGS} -c $< -o $@

$(NAME): ${OBJS} ${OBJS_MLX}
		make -C mlx
		make -C libft
		${CC} ${OBJS} ${OBJS_MLX} ${LIBFT_FLAGS} ${MATH_FLAGS} ${MLX_FLAGS} -o ${NAME} 
clean:
		make -C mlx clean
		make -C libft clean
		${RM} ${OBJS} ${OBJS_FULL} ${OBJS_MLX} ${OBJS_TERM}


fclean:		clean
		rm -f libft/libft.a
		${RM} ${NAME}

re:		fclean
	make all

.PHONY : all clean fclean re
