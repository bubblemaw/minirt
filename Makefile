# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maw <maw@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 12:39:32 by masase            #+#    #+#              #
#    Updated: 2025/06/11 17:20:28 by maw              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRCS = 	srcs/main.c \
		srcs/parsing.c \
		srcs/save_ambiance.c \
		srcs/save_camera.c \
		srcs/save_light.c \
		srcs/save_plane.c \
		srcs/save_sphere.c \
		srcs/save_cylinder.c \
		srcs/utils.c \
		srcs/error_message.c \
		srcs/print_struct.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Werror -Wextra -g3

RM = rm -f

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)/libft.a

MLX_PATH = minilibx-linux/

MLX_LIB = $(MLX_PATH)libmlx_Linux.a

MLX_FLAGS = -Lminilibx-linux -L/usr/lib/X11 -lXext -lX11

$(NAME): subsystems $(OBJS)
		gcc $(FLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)

%.o: %.c 
	gcc $(FLAGS) -c $< -o $@

subsystems: 
		@make -C $(MLX_PATH) all
		@make -C $(LIBFT_PATH) all

all: $(NAME)

clean:
		$(RM) $(OBJS)
		make -C $(LIBFT_PATH) clean
		make -C $(MLX_PATH) clean

		
fclean: clean
		$(RM) $(NAME)
		make -C $(LIBFT_PATH) fclean
		make -C $(MLX_PATH) clean

re: fclean all