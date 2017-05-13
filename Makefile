# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 14:52:17 by gguiulfo          #+#    #+#              #
#    Updated: 2017/05/13 07:41:46 by gguiulfo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minishell

CC			:= gcc
CFLAGS		+= -Wall -Wextra
CFLAGS		+= -Werror
# CFLAGS 		+= -g
CFLAGS		+= -I includes -I libft/includes
LDFLAGS		+= -L libft/ -lft
LDFLAGS		+= alloc_wrap.c

LIBFT		:= libft/libft.a

REGULAR		:= msh_main msh_exec msh_utils msh_strsplit
BUILTINS	:= msh_echo msh_cd msh_extra msh_env

FILES		:=	$(addprefix builtins/, $(BUILTINS)) \
				$(REGULAR)

SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(SRC:.c=.o)

.PHONY = all clean fclean re

all: $(NAME)

$(LIBFT):
	@make -C libft

$(OBJ): %.o: %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(LDFLAGS) -o $@ $^
	@echo "\033[32mCompiled Executable\033[0m"

clean:
	@rm -rf $(OBJ)
	@make -C libft clean
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean
	@echo "\033[32mRemoved Executable\033[0m"

re: fclean all
