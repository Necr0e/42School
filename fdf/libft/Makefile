# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 10:06:39 by oseitama          #+#    #+#              #
#    Updated: 2022/10/14 11:35:04 by oseitama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -c -g

#sources
SRC_DIR = srcs/
SRCS =	ft_abs.c ft_atoi.c ft_bzero.c \
		ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_isspace.c \
		ft_itoa.c ft_lstadd.c ft_lstdel.c \
		ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
		ft_lstnew.c ft_memalloc.c ft_memccpy.c \
		ft_memchr.c ft_memcmp.c ft_memcpy.c \
		ft_memdel.c ft_memmove.c ft_memset.c \
		ft_minmax.c ft_pow.c ft_putchar_fd.c \
		ft_putchar.c ft_putendl_fd.c ft_putendl.c \
		ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c \
		ft_putstr.c ft_strcat.c ft_strchr.c \
		ft_strclr.c ft_strcmp.c ft_strcpy.c \
		ft_strdel.c ft_strdup.c ft_strequ.c \
		ft_striter.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlen.c ft_strmap.c \
		ft_strmapi.c ft_strncat.c ft_strncmp.c \
		ft_strncpy.c ft_strnequ.c ft_strnew.c \
		ft_strnstr.c ft_strrchr.c ft_strsplit.c \
		ft_Strstr.c ft_strsub.c ft_strtrim.c \
		ft_tolower.c ft_toupper.c ft_wordcount.c \
		ft_wordlen.c ft_calloc.c ft_atol.c \
		ft_atoi_base.c ft_arr_len.c
SRCS_COMPILE = $(addprefix $(SRC_DIR), $(SRCS))

#get_next_line
GNL_DIR = get_next_line/
GNL = get_next_line.c
SRCS_GNL = $(addprefix $(GNL_DIR), $(GNL))

#objects
OBJS = $(SRCS:%.c=%.o)
OBJS_GNL = $(GNL:%.c=%.o)

all: $(NAME)

$(NAME):$(OBJS_GNL)
	@$(CC) $(CFLAGS) $(SRCS_COMPILE)
	@ar rc $(NAME) $(OBJS)
	@echo "gnl added to libft"
	@ar -rcs $(NAME) $(OBJS_GNL)
	@echo "libft.a built"
$(OBJS_GNL) : $(SRCS_GNL)
	@$(CC) $(CFLAGS) $(SRCS_GNL)

clean:
	@rm -f $(OBJS)
	@rm -f $(OBJS_GNL)

fclean: clean
	@rm -f $(NAME)

re: fclean all

help:
	@echo "all $(NAME) clean fclean re \033[0;32m help\033[0;39m"

.PHONY:		all clean fclean re help
