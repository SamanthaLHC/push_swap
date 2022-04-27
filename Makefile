# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sam <sam@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 15:24:23 by sle-huec          #+#    #+#              #
#    Updated: 2022/04/27 11:43:44 by sam              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap	

CFLAGS = -MMD -Wall -Wextra -Werror -g3
CC = cc
SRCS = 		$(addprefix $(SRCS_PATH), \
				push_swap.c \
				check_input.c \
				parsing.c \
				mv_swap.c \
				handle_struct.c \
			)
INCLUDES = -I./\
		-I./ft_libft_printf\
		-I./ft_libft_printf/libft

SRCS_PATH = ./srcs/
OBJ_PATH = ./objs/
LIBFT = ./ft_libft_printf/libftprintf.a	


OBJ = $(SRCS:$(SRCS_PATH)%.c=$(OBJ_PATH)%.o)
DEP = $(SRCS:$(SRCS_PATH)%.c=$(OBJ_PATH)%.d)


all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -o $(NAME) $(LIBFT)

${LIBFT}:
		make -C ./ft_libft_printf all

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c 
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -rf $(OBJ) $(DEP)
	rm -rf $(OBJ_PATH)
	make -C ./ft_libft_printf/ clean

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean
	make -C ./ft_libft_printf re
	make all

.PHONY: all clean fclean re

-include $(DEP)
