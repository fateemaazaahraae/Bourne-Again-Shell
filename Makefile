# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiima <tiima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 17:05:39 by tiima             #+#    #+#              #
#    Updated: 2024/07/08 18:14:01 by tiima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lreadline
INCLUDES = -Iincludes
LIBFT = libft/libft.a
SRC = ./src/main.c 
EXECUTION_SRC = ./src/execution/builtins/cd.c ./src/execution/builtins/echo.c
PARCING_SRC = ./src/parcing/hello.c

OBJ = $(SRC:.c=.o) $(EXECUTION_SRC:.c=.o) $(PARCING_SRC:.c=.o)

all: $(NAME) $(LIBFT)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

$(LIBFT):
	make -C libft && make bonus -C libft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
