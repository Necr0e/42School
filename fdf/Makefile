# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/10 06:00:47 by oseitama          #+#    #+#              #
#    Updated: 2022/10/13 15:07:30 by oseitama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
FLAGS = -Wall -Wextra -Werror
HEADERS = -I$(LIBFT_DIR) -I$(HEADER_DIR)

LIBFT_DIR = ./libft/
LIBFT = ./libft/libft.a
SRC_DIR = srcs/
HEADER_DIR = ./includes

LIBRARIES = -lm -lft -L$(LIBFT_DIR) -L /usr/local/bin -lmlx -framework OpenGL -framework AppKit

SRC_FILES = main.c init.c exit.c	\
	additional_keys.c bresenham.c	\
	colors.c draw.c draw_utils.c	\
	events.c move_pixels.c utils.c	\
	parser.c parser_utils.c pixel_manip.c

FUNCTIONS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJECTS = $(partsubst $(SRC_DIR), $(OBJ_DIR),$(OBJ_FILES))
OBJ_FILES = $(FUNCTIONS:.c=.o)
OBJ_DIR = ./objects/

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(FUNCTIONS) $(HEADERS) $(LIBRARIES)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(HEADERS) -o $@ -c $<

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re: fclean all
