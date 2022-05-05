/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:05:34 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/05 17:26:19 by sam              ###   ########.fr       */
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
	struct s_link	*prev;
}							t_link;

typedef struct s_info
{
	int		stack_size;
	int		index_arg;
}		t_info;

/* ************************************************************************** */
/*    utils_add_elem.c                                                        */
/* ************************************************************************** */

t_link	*ft_lstnew_int(int nb);
void	ft_link_back(t_link **alst, t_link *new);
void	ft_link_front(t_link **alst, t_link *new);

/* ************************************************************************** */
/*    utils_handle_list.c                                                     */
/* ************************************************************************** */

void	ft_free_list(t_link *linked_list);
t_link	*ft_get_last(t_link *lst);
int		count_elem_in_stack(t_link *stack);
int		ft_is_sorted(t_link *stack);
void	print_arg(t_link *list);

/* ************************************************************************** */
/*    check_input.c                                                           */
/* ************************************************************************** */

int		ft_input_is_digit(char *input);
int		ft_duplicate(t_link *stack_a);
int		ft_check_before_parsing(char *input, t_info *struct_info);

/* ************************************************************************** */
/*    parsing.c                                                               */
/* ************************************************************************** */

int		get_element_from_input(char *input, t_link **stack_a);
//int		ft_sort_stack(t_link **stack);

/* ************************************************************************** */
/*    mv_swap.c                                                               */
/* ************************************************************************** */

void	ft_swap(t_link **stack_a);
int		ft_sa(t_link **stack_a);
int		ft_sb(t_link **stack_b);
int		ft_ss(t_link **stack_a, t_link **stack_b);
int		which_swap(t_link **stack, int src_is_a);

/* ************************************************************************** */
/*    mv_rotate.c                                                             */
/* ************************************************************************** */

void	ft_rotate(t_link **stack);
int		ft_ra(t_link **stack_a);
int		ft_rb(t_link **stack_b);
int		ft_rr(t_link **stack_a, t_link **stack_b);
int		which_rotate(t_link **stack, int src_is_a);

/* ************************************************************************** */
/*    mv_reverse_rotate.c                                                     */
/* ************************************************************************** */

void	ft_reverse_rotate(t_link **stack);
int		ft_rra(t_link **stack_a);
int		ft_rrb(t_link **stack_b);
int		ft_rrr(t_link **stack_a, t_link **stack_b);
int		which_rr(t_link **stack, int src_is_a);

/* ************************************************************************** */
/*    mv_push.c                                                               */
/* ************************************************************************** */

void	ft_push(t_link **stack_src, t_link **stack_dst);
int		ft_pa(t_link **stack_b, t_link **stack_a);
int		ft_pb(t_link **stack_a, t_link **stack_b);
int		which_push(t_link **stack_src, t_link **stack_buf, int src_is_a);

/* ************************************************************************** */
/*    sort.c                                                                  */
/* ************************************************************************** */

//void	ft_sort_and_set_index(char *input, t_info *struct_info);
int		ft_split_pivot(t_link **stack_src, t_link **stack_buf, int src_is_a);
int		ft_quick_sort(t_link **stack_src, t_link **stack_buf, int src_is_a, int call);

#endif