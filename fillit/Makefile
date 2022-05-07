# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lharkala <lharkala@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 11:09:04 by lharkala          #+#    #+#              #
#    Updated: 2022/05/03 12:04:38 by lharkala         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRCS = 	main.c \
		parser.c \
		valid.c \
		solver.c \
		map.c \
		utils.c

OBJS = $(SRCS:.c=.o)

LIB = libft

all: $(NAME)

$(NAME):
	$(MAKE) -C ./$(LIB)
	gcc $(FLAGS) -c $(SRCS)
	gcc $(FLAGS) $(OBJS) -I. -o $(NAME) libft/libft.a

clean:
	rm -f $(OBJS)
	$(MAKE) -C ./$(LIB) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ./$(LIB) fclean

re: fclean all

.PHONY: all clean fclean re
