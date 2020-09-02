<<<<<<< HEAD
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
=======
NAME = cub3d

FLAGS = -Wall -Wextra -Werror

SRCS =	srcs/init/initialize_cub3d.c \
	srcs/init/initialize_mlx_window.c \
	srcs/init/init_params.c \
	srcs/init/validate_params.c \
	srcs/init/set_params_to_default.c \
	srcs/parsing/validate_file.c \
	srcs/parsing/set_params.c \
	srcs/parsing/set_map.c \
	srcs/parsing/validate_map.c \
	srcs/parsing/set_resolution.c \
	srcs/parsing/set_texture.c \
	srcs/parsing/set_floor_color.c \
	srcs/parsing/set_ceiling_color.c \
	srcs/parsing/set_player_position.c \
	srcs/parsing/validate_line_type1.c \
	srcs/parsing/validate_line_type2.c \
	srcs/parsing/set_sprites.c \
	srcs/raycasting/dda_init.c \
	srcs/raycasting/dda_perform.c \
	srcs/raycasting/dda_data.c \
	srcs/raycasting/draw_textured_stripe.c \
	srcs/raycasting/sort_sprites.c \
	srcs/raycasting/sprites_distance.c \
	srcs/raycasting/draw_sprites.c \
	srcs/utils/draw_scene.c \
	srcs/utils/buffer_to_image.c \
	srcs/events/keyhook.c \
	srcs/events/close_button.c \
	srcs/events/camera_left.c \
	srcs/events/camera_right.c \
	srcs/events/move_forward.c \
	srcs/events/move_backward.c \
	srcs/events/move_left.c \
	srcs/events/move_right.c \
	srcs/save_scene.c \
	srcs/display_scene.c \
	srcs/quit_program.c \

$(NAME): mk_lft mk_lbitmapfile mk_lmlx
	gcc -g $(FLAGS) $(SRCS) main.c -lz -L./libmlx -lmlx -framework OpenGL -framework AppKit -I./srcs/ -L./libft -lft -L./libbitmapfile -lbitmapfile -o cub3d -lm

all: $(NAME)

mk_lft:
		cd libft/ && make

mk_lbitmapfile:
		cd libbitmapfile/ && make
mk_lmlx:
	cd libmlx/ && make

cleanlmlx:
	cd libmlx/ && make clean

cleanlft:
	cd libft/ && make clean

cleanlbitmapfile:
	cd libbitmapfile/ && make clean

clean: cleanlmlx cleanlft cleanlbitmapfile

fcleanlft:
	cd libft/ && make fclean

fcleanlbitmapfile:
	cd libbitmapfile/ && make fclean

fclean: fcleanlft fcleanlbitmapfile clean
	rm -f cub3d *.bmp

re: fclean all

norme:
	norminette main.c libft/ libbitmapfile/ srcs/
>>>>>>> e0eb398aa0f075849c0b55de1001e8c793dd29df
