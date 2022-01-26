# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpolonen <tpolonen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/17 14:27:14 by tpolonen          #+#    #+#              #
#    Updated: 2022/01/26 14:26:50 by jturunen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EVAL = ~/repos/home_repos/get_next_line/

all:
	make -C $(EVAL)libft/ fclean && make -C $(EVAL)libft/
	clang -g -Wall -Wextra -Werror -I $(EVAL) -I $(EVAL)libft/includes -I $(EVAL)libft/ -o $(EVAL)get_next_line.o -c $(EVAL)get_next_line.c
	clang -g -Wall -Wextra -Werror -I $(EVAL) -I $(EVAL)libft/includes -I $(EVAL)libft/ -o main.o -c main.c
	clang -g -o test_gnl main.o $(EVAL)get_next_line.o -I $(EVAL)libft/includes -I $(EVAL)libft -L $(EVAL)libft/ -lft
