# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nainhaja <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/30 18:45:53 by nainhaja          #+#    #+#              #
#    Updated: 2021/06/30 18:45:55 by nainhaja         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex.a
CC = gcc -Wall -Wextra -Werror -o Pipex 

SRC = pipex.c ft_absolute.c ft_comands.c ft_functions.c \
		ft_getpath.c ft_putsstr.c ft_split.c ft_strjoin.c \

NAME = Pipex

all: $(NAME)

$(NAME): 
	$(CC) $(SRC)

clean:
	rm -f $(NAME)

fclean: clean	
	rm -f $(NAME)

re : fclean all
