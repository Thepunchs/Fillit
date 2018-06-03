# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alefebvr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/24 12:38:55 by alefebvr          #+#    #+#              #
#    Updated: 2017/12/14 22:10:27 by alefebvr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

OBJ = ft_final_tab.o ft_valid.o ft_get_tab.o ft_get_last_tab.o ft_resolve.o\
	  main.o

SRC = $(OBJ:.o=.c)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRC) fillit.h
	make -C libft
	gcc -c $(FLAGS) $(SRC)
	gcc -o $(NAME) $(OBJ) libft/libft.a
	rm -rf $(OBJ)
clean :
	rm -rf $(OBJ)
	make clean -C libft

fclean : clean
	rm -rf $(NAME)
	rm libft/libft.a

re : fclean all

.PHONY : all clean fclean re
