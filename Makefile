# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 10:06:30 by aakouhar          #+#    #+#              #
#    Updated: 2024/07/22 19:03:31 by fbazaz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lreadline
INCLUDES = -Iincludes
LIBFT = libft/libft.a

SRC = ./src/main.c 
#EXECUTION_SRC = ./src/execution/builtins/cd.c ./src/execution/builtins/echo.c ./src/execution/builtins/get_env.c ./src/execution/builtins/get_env_utils.c \
				./src/execution/builtins/pwd.c ./src/execution/builtins/env.c ./src/execution/builtins/unset.c
PARCING_SRC = ./src/parcing/fill.c ./src/parcing/check.c ./src/parcing/errors.c ./src/parcing/ft_parcing.c ./src/parcing/parcing_utils.c ./src/parcing/files.c \
				./src/parcing/redir_lst_utils.c ./src/parcing/fill_cmd_args.c

OBJ = $(SRC:.c=.o) $(EXECUTION_SRC:.c=.o) $(PARCING_SRC:.c=.o)

all: $(LIBFT) $(NAME) 

$(LIBFT):
	make -C libft && make bonus -C libft

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(LIBS) -o $(NAME)
	@clear

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C libft
	rm -rf $(OBJ)
	@clear

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
