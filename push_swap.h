/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:05:34 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/27 12:16:48 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_link
{
	int				nb;
	struct s_link	*next;
}							t_link;

typedef struct s_info
{
	int	stack_size;
	int	index_arg;
}		t_info;

/* ************************************************************************** */
/*    handle_struct.c                                                         */
/* ************************************************************************** */

t_link	*ft_lstnew_int(int nb);
t_link	*ft_link_last(t_link *lst);
void	ft_link_back(t_link **alst, t_link *new);
void	ft_free_list(t_link *linked_list);

/* ************************************************************************** */
/*    check_input.c                                                           */
/* ************************************************************************** */

int		ft_input_is_digit(char *input);
int		ft_duplicate(char *input);
int		ft_check_before_parsing(char *input, t_info *struct_info);

/* ************************************************************************** */
/*    parsing.c                                                               */
/* ************************************************************************** */

int		get_element_from_input(char *input, t_link **stack_a);

/* ************************************************************************** */
/*    mv_swap.c                                                               */
/* ************************************************************************** */

void	ft_swap(t_link **stack_a);
int		ft_sa(t_link **stack_a, t_info *struct_info);
int		ft_sb(t_link **stack_b, t_info *struct_info);
void	ft_ss(t_link **stack_a, t_link **stack_b);

/* ************************************************************************** */
/*    mv_rotate.c                                                             */
/* ************************************************************************** */

#endif