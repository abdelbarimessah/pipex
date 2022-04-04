# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amessah <amessah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/17 21:13:54 by amessah           #+#    #+#              #
#    Updated: 2022/04/04 00:59:25 by amessah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAME_BNS = pipex_bonus

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = pipex.h

src =	main.c		\
		pipex.c		\
		ft_utils.c	\
		ft_utils2.c	\

src_bns =	main_bonus.c \
			pipex.c		\
			ft_utils.c	\
			ft_utils2.c	\
			gnl.c 		\

obj_bns = $(src_bns:.c=.o)

OBJECTS = $(src:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

bonus: $(NAME_BNS)

$(NAME_BNS): $(obj_bns) $(INCLUDE)
	$(CC) $(CFLAGS) $(obj_bns) -o $(NAME_BNS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJECTS) $(obj_bns)

fclean: clean
	rm -rf $(NAME) $(NAME_BNS)

re: fclean all bonus