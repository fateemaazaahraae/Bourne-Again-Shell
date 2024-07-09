# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tiima <tiima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 15:04:18 by fbazaz            #+#    #+#              #
#    Updated: 2024/07/08 18:06:46 by tiima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFILE = ft_isalpha.c ft_isdigit.c ft_strlen.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c ft_atoi.c ft_strdup.c ft_strnstr.c ft_strchr.c \
		ft_strjoin.c ft_split.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c
BFILE = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c
OFILE = $(CFILE:.c=.o)
BOBJT = $(BFILE:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OFILE)
		  ar rcs $(NAME) $(OFILE)

bonus : $(BOBJT)

$(BOBJT) : $(BFILE)
		$(CC) $(CFLAGS) -c $(BFILE)
		ar rcs  $(NAME) $(BOBJT)

clean :
	rm -f $(OFILE) $(BOBJT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
