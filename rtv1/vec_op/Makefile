# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 17:14:08 by oseitama          #+#    #+#              #
#    Updated: 2023/01/28 17:18:58 by oseitama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = veclib.a

FLAGS = -Wall -Wextra -Werror

SRC = vec_dot.c vec_len.c vec_norm.c \
	vec_scale.c vec_sub.c vec_sum.c \
	vec_rot.c vec_rotx.c vec_roty.c vec_rotz.c

OBJ = $(SRC:.c=.o)
HEADER = vec_op.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@gcc -c $(SRC) $(FLAGS)
	@ar rc $(NAME) $(OBJ) $(HEADER)
	@printf "Compiling vec_op.a done\n"

.c.o: $(HEADER)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@printf "All objects deleted.\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "Vector operatikons library is clean.\n"

re: fclean all

.PHONY: all clean fclean re
