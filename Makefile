# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
<<<<<<< HEAD
#    By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 17:05:39 by tiima             #+#    #+#              #
#    Updated: 2024/07/09 16:10:03 by fbazaz           ###   ########.fr        #
=======
#    By: aakouhar <aakouhar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 17:05:39 by tiima             #+#    #+#              #
#    Updated: 2024/07/09 18:52:11 by aakouhar         ###   ########.fr        #
>>>>>>> 5ef2f3d8bfd47488cbd158d68b9c6fb409dc3cda
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lreadline
INCLUDES = -Iincludes
LIBFT = libft/libft.a

SRC = ./src/main.c 
<<<<<<< HEAD
EXECUTION_SRC = ./src/execution/builtins/cd.c ./src/execution/builtins/echo.c ./src/execution/builtins/get_env.c ./src/execution/builtins/get_env_utils.c \
				./src/execution/builtins/pwd.c ./src/execution/builtins/env.c ./src/execution/builtins/unset.c
PARCING_SRC = ./src/parcing/hello.c
=======
EXECUTION_SRC = ./src/execution/builtins/cd.c ./src/execution/builtins/echo.c ./src/execution/builtins/get_env.c
PARCING_SRC = ./src/parcing/fill.c ./src/parcing/check.c ./src/parcing/errors.c
>>>>>>> 5ef2f3d8bfd47488cbd158d68b9c6fb409dc3cda

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
