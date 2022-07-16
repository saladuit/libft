# **************************************************************************** #
#                                                                              #
#                                                     .--.  _                  #
#    Makefile                                        |o_o || |                 #
#                                                    |:_/ || |_ _   ___  __    #
#    By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /    #
#                                                  (|     | )|_| |_| |>  <     #
#    Created: 2022/02/09 17:06:29 by safoh        /'\_   _/`\__|\__,_/_/\_\    #
#    Updated: 2022/07/16 20:43:00 by safoh        \___)=(___/                  #
#                                                                              #
# **************************************************************************** #

include makerc/colours.mk
include makerc/libft.mk

################################################################################
NAME			=libft.a

CC				:=gcc
RM				:=rm -rf
CFLAGS			=-Wall -Wextra -Werror$(if $(DEBUG), -g -fsanitize=address)\
				 $(if $(MALLOC), -g)

SRC_DIR 		:=./src
BUILD_DIR		:=./build
OBJS			=$(addprefix $(BUILD_DIR)/, $(SRCS:%.c=%.o))
HEADERS			=include/libft.h
INCLUDE_FLAGS	=$(addprefix -I, $(sort $(dir $(HEADERS))))

################################################################################
all: $(NAME)

$(NAME): SHELL :=/bin/bash

$(NAME): $(OBJS)
	@ar rc $@ $^
	@printf "$(BLUE_FG)$(NAME)$(RESET_COLOR) created\n"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

################################################################################
clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME) *.a *.dSYM

re: all
	@$(MAKE) fclean

debug:
	@$(MAKE) DEBUG=1

.PHONY: all clean fclean re debug
################################################################################
