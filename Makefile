# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 15:24:23 by sle-huec          #+#    #+#              #
#    Updated: 2022/04/15 13:36:20 by sle-huec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g3

SRC = push_swap.c

NAME = push_swap	

INC = 	-I .\
		-I ./ft_libft_printf\
		-I ./ft_libft_printf/libft

LIBFT = ./ft_libft_printf/libftprintf.a
	
OBJ = $(SRC:%.c=%.o)
	
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	ar -rcs $(NAME) $(OBJ)

${LIBFT}:
		make -C ./ft_libft_printf

%.o: %.c 
	cc $(CFLAGS) -c $< -o $@ $(INC)

clean:
	rm -re $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean	
	make all

.PHONY: all clean fclean re
