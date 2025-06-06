# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masase <masase@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 12:39:32 by masase            #+#    #+#              #
#    Updated: 2025/06/06 13:23:40 by masase           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

SRCS = srcs/main.c

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Werror -Wextra -g3

RM = rm -f

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)/libft.a

$(NAME): subsystems $(OBJS)
		gcc $(FLAGS) $(OBJS) -o $(NAME) $(LIBFT_LIB)

%.o: %.c 
	gcc $(FLAGS) -c $< -o $@

subsystems: 
		@make -C $(LIBFT_PATH) all

all: $(NAME)

clean:
		$(RM) $(OBJS)
		make -C $(LIBFT_PATH) clean
		
fclean: clean
		$(RM) $(NAME)
		make -C $(LIBFT_PATH) fclean

re: fclean all