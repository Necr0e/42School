# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 16:11:40 by oseitama          #+#    #+#              #
#    Updated: 2022/09/21 16:13:20 by oseitama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c handle_hooks.c mandelbrot.c color.c \
		utils.c fractol.c julia.c burningship.c
OBJS = $(SRCS:.c=.o)
NAME = fractol
HEADER = fractol.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -O3

MLX_FLAG = -lm -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(MLX_FLAG) $(FLAGS) $(OBJS) -o $(NAME)

bonus : all

%.o : %.c
	$(CC) $(FLAGS) -c $<
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
