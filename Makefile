# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoannguy <hoannguy@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 12:39:32 by masase            #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2025/06/07 21:21:11 by hoannguy         ###   ########.fr        #
=======
#    Updated: 2025/06/06 15:07:39 by masase           ###   ########.fr        #
>>>>>>> 307e3be1b42f2e1c9abf858a8b8536cdf8154815
#                                                                              #
# **************************************************************************** #

NAME = miniRT

SRCS = 	srcs/main.c \
		srcs/rayon_start.c\

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Werror -Wextra -g3

RM = rm -f

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)/libft.a

MLX_PATH = minilibx-linux/

MLX_LIB = $(MLX_PATH)libmlx_Linux.a

MLX_FLAGS = -Lminilibx-linux -L/usr/lib/X11 -lXext -lX11

$(NAME): subsystems $(OBJS)
<<<<<<< HEAD
		@gcc $(FLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)
		@echo "made $(NAME)"
=======
		gcc $(FLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) $(MLX_FLAGS) -o $(NAME)
>>>>>>> 307e3be1b42f2e1c9abf858a8b8536cdf8154815

%.o: %.c 
		@gcc $(FLAGS) -c $< -o $@

subsystems: 
		@make -C $(MLX_PATH) all
		@make -C $(LIBFT_PATH) all
		@echo "dependencies compiled"

all: $(NAME)

clean:
		$(RM) $(OBJS)
<<<<<<< HEAD
		@make -C $(LIBFT_PATH) clean
		@make -C $(MLX_PATH) clean
		@echo "delete object files"
=======
		make -C $(LIBFT_PATH) clean
		make -C $(MLX_PATH) clean
>>>>>>> 307e3be1b42f2e1c9abf858a8b8536cdf8154815

		
fclean: clean
		$(RM) $(NAME)
<<<<<<< HEAD
		@make -C $(LIBFT_PATH) fclean
		@make -C $(MLX_PATH) clean
		@echo "delete $(NAME)"
=======
		make -C $(LIBFT_PATH) fclean
		make -C $(MLX_PATH) fclean
>>>>>>> 307e3be1b42f2e1c9abf858a8b8536cdf8154815

re: fclean all