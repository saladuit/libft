# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: saladin <saladin@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/03 16:48:59 by saladin       #+#    #+#                  #
#    Updated: 2021/01/14 18:24:07 by saladin       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
OBJ_FILES = ft_memset.o ft_bzero.o ft_memcpy.o ft_memccpy.o ft_memmove.o  \
		ft_memcmp.o ft_strlen.o ft_strlcpy.o ft_strlcat.o ft_strchr.o \
		ft_strrchr.o ft_strnstr.o ft_strncmp.o ft_atoi.o  ft_isalpha.o \
		ft_isdigit.o ft_isalnum.o ft_isascii.o ft_isprint.o ft_toupper.o \
		ft_tolower.o  ft_putchar_fd.o ft_putstr_fd.o ft_putendl_fd.o  \
		ft_strdup.o ft_substr.o ft_strjoin.o  ft_strtrim.o ft_split.o  \
		ft_putnbr_fd.o ft_calloc.o ft_memchr.o ft_strmapi.o ft_itoa.o
HEADER_FILES = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_FILES)
		ar rc $(NAME) $^

%.o: %.c $(HEADER_FILES)
		$(CC) -c $(CFLAGS) -o $@ $<

clean:
		rm -f $(OBJ_FILES)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
