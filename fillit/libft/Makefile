# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oseitama <oseitama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 10:06:39 by oseitama          #+#    #+#              #
#    Updated: 2022/04/22 11:07:16 by oseitama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_bzero.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c
SRC += ft_memset.c ft_strcat.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_strncat.c
SRC += ft_strncpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c
SRC += ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c
SRC += ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_tolower.c
SRC += ft_toupper.c  ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c
SRC += ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c
SRC += ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c
SRC += ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c
SRC += ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c
SRC += ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c
SRC += ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_isspace.c
SRC += ft_wordcount.c ft_wordlen.c ft_lstrev.c ft_lstcount.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@gcc -Wall -Wextra -Werror -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re