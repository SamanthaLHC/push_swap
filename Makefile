# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 15:24:23 by sle-huec          #+#    #+#              #
#    Updated: 2022/04/08 17:06:41 by sle-huec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -g3

SRC = push_swap.c \
	  utils.c 	

NAME = push_swap	

OBJ = $(SRC:%.c=%.o)
	
all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

%.o: %.c 
	cc $(CFLAGS) -c $< -o $@ -I .

clean:
	rm -re $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean	
	make all

.PHONY: all clean fclean re
