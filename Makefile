# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salee <salee@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/29 19:31:06 by salee             #+#    #+#              #
#    Updated: 2022/01/29 19:37:42 by salee            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCE = ./ft_itoa_hexa.c	\
./ft_itoa.c					\
./ft_printf.c				\
./ft_put_anything.c			\

OBJECT = $(SOURCE:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJECT)
	ar rcs $(NAME) $(OBJECT)

%.o : %.c
	gcc -Wall -Wextra -Werror -c $< -o $@

clean :
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
