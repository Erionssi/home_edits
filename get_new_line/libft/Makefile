# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jturunen <jturunen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/04 16:12:58 by jturunen          #+#    #+#              #
#    Updated: 2021/12/17 13:49:11 by jturunen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
FUNCTIONS := ft_putchar ft_strlen ft_putstr ft_strcmp ft_strcpy ft_strchr \
	ft_strrchr ft_atoi ft_putnbr ft_putendl ft_strdup ft_memset ft_bzero \
	ft_memcpy ft_memccpy ft_memmove ft_memchr ft_memcmp ft_strncpy \
	ft_strcat ft_strncat ft_strlcat ft_strstr ft_strncmp ft_isalpha \
	ft_isdigit ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower \
	ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr ft_striter ft_striteri \
	ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim \
	ft_strsplit ft_itoa ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd \
	ft_lstnew ft_lstdelone ft_lstdel ft_strnstr ft_lstadd ft_lstiter ft_lstmap
 
OBJS := $(foreach obj, $(FUNCTIONS), $(addsuffix .o, $(obj)))
SRCS := $(foreach src, $(FUNCTIONS), $(addsuffix .c, $(src)))

RM := /bin/rm -f
WWW := -Wall -Werror -Wextra
INCLUDES := -I includes


.PHONY: all clean fclean re so

all: $(NAME)

$(NAME):
	gcc -c $(WWW) $(SRCS) $(INCLUDES)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) libft.so

re: fclean all

run: re
	gcc $(WWW) main.c -o run_test -L. -lft
	./run_test

so:
	clang-11 -nostartfiles -fPIC $(WWW) $(SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS)
