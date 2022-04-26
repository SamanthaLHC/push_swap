/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:05:34 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/25 18:51:08 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_linked_list
{
	int						nb;
	struct s_linked_list	*next;
}							t_linked_list;

typedef struct s_struct_info
{
	int	stack_size;
	int	index_arg;
}		t_struct_info;

/* ************************************************************************** */
/*    handle_struct.c                                                         */
/* ************************************************************************** */

void	init_struct_info(t_struct_info *struct_info);
t_list	*ft_lstnew_int(int content);

/* ************************************************************************** */
/*    check_input.c                                                           */
/* ************************************************************************** */

int		ft_input_is_digit(char *input);
int		ft_duplicate(char *input);
int		ft_check_before_parsing(char *input);

/* ************************************************************************** */
/*    parsing.c                                                               */
/* ************************************************************************** */

int		get_element_from_input(char *input, t_linked_list **linked_list);

/* ************************************************************************** */
/*    mv_swap.c                                                               */
/* ************************************************************************** */

void	ft_swap(t_list **pile);
int		ft_sa(t_list **pile_a);
int		ft_sb(t_list **pile_b);
void	ft_ss(t_list **pile_a, t_list **pile_b);

/* ************************************************************************** */
/*    mv_rotate.c                                                             */
/* ************************************************************************** */

#endif