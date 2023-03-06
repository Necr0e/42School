# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 14:29:52 by oseitama          #+#    #+#              #
#    Updated: 2023/01/31 16:33:17 by oseitama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
SRC = srcs/main.c srcs/cylinder.c srcs/light.c \
	srcs/cone.c srcs/parse.c srcs/plane.c \
	srcs/sphere.c srcs/ray_trace.c srcs/validation.cone

OBJ = $(SRC:.c=.o)
LIBS = libft/libft.a vec_op/veclib.a
HEADERS = -I ./include -I ./libft -I ./vec_op
HDR = include/rtv1.h
FLAGS = -Wall -Wextra -Werror
CGFLAGS = -lmlx -framework OpenGL -framework AppKit
INCLUDES = -I ./frameworks/SDL2.framework/Versions/A/Headers \
	-I ./frameworks/SDL2.ttf.framework/Versions/A/Headers \
	-I ./frameworks/SDL2.image.framework/Versions/A/Headers \
	-I ./frameworks/SDL2.mixer.framework/Headers \
	-F ./frameworks/
FRAMEWORKS = -F ./frameworks/ -rpath ./frameworks \
	-framework OpenGL -framework AppKit -framework OpenCL \
	-framework SDL2 -framework SDL2_ttf -framework SDL2_image \
	-framework SDL2_mixer

all: $(NAME)

$(NAME): libft/libft.a vec_op/veclib.a $(OBJ) $(HDR)
	@gcc $(FLAGS) $(CGFLAGS) $(FRAMEWORKS) $(OBJ) $(LIBS) -o $(NAME)
	@printf "Compiling RTv1 done\n"

.c.o: $(HDR)
	@gcc $(FLAGS) $(INCLUDES) $(HEADERS) -c $< -o $@

clean:
	@make clean -C libft
	@make clean -C vec_op
	@rm -rf $(OBJ)
	@printf "All objects of RTv1 were deleted.\n"

fclean:
	@make fclean -C libft
	@make fclean -C vec_op
	@rm -rf $(OBJ)
	@rm -rf $(NAME)
	@printf "All objects and binaries of RTv1 were deleted.\n"

libft/libft.a:
	@make -C libft

vec_op/veclic.a:
	@make -C vec_op

re: fclean all
