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
