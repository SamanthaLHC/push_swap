/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:05:34 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/08 16:37:20 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef enum rotate_way
{
	ROTATE,
	ROT_REVERSE,
}			t_way;

typedef struct s_link
{
	int				nb;
	struct s_link	*next;
	struct s_link	*prev;
}					t_link;

typedef struct s_info
{
	int		stack_size;
}			t_info;

typedef struct s_score
{
	t_link	*pos_in_a;
	t_link	*pos_in_b;
	t_way	way_a;
	t_way	way_b;
	int		moves_a;
	int		moves_b;
}			t_score;

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
void	print_arg(t_link *list);
int		ft_is_sorted(t_link *stack);

/* ************************************************************************** */
/*    utils_sort.c                                                            */
/* ************************************************************************** */

void	ft_sort_three(t_link **stack);
t_link	*get_smallest(t_link *stack);
t_link	*get_insert_pos(t_link *stack_a, int elem);
int		get_nb_move_and_way(t_link	*pos, t_way *way);

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

/* ************************************************************************** */
/*    mv_swap.c                                                               */
/* ************************************************************************** */

void	ft_swap(t_link **stack_a);
void	ft_sa(t_link **stack_a);
void	ft_sb(t_link **stack_b);
void	ft_ss(t_link **stack_a, t_link **stack_b);
//int	which_swap(t_link **stack, int src_is_a);

/* ************************************************************************** */
/*    mv_rotate.c                                                             */
/* ************************************************************************** */

void	ft_rotate(t_link **stack);
void	ft_ra(t_link **stack_a);
void	ft_rb(t_link **stack_b);
void	ft_rr(t_link **stack_a, t_link **stack_b);
//int	which_rotate(t_link **stack, int src_is_a);

/* ************************************************************************** */
/*    mv_reverse_rotate.c                                                     */
/* ************************************************************************** */

void	ft_reverse_rotate(t_link **stack);
void	ft_rra(t_link **stack_a);
void	ft_rrb(t_link **stack_b);
void	ft_rrr(t_link **stack_a, t_link **stack_b);
//int	which_rr(t_link **stack, int src_is_a);

/* ************************************************************************** */
/*    mv_push.c                                                               */
/* ************************************************************************** */

void	ft_push(t_link **stack_src, t_link **stack_dst);
void	ft_pa(t_link **stack_b, t_link **stack_a);
void	ft_pb(t_link **stack_a, t_link **stack_b);
void	ft_push_until_three(t_link **stack_a, t_link **stack_b);
//int	which_push(t_link **stack_src, t_link **stack_buf, int src_is_a);

/* ************************************************************************** */
/*    sort.c                                                                  */
/* ************************************************************************** */

void	select_elem_to_push(t_link **stack_a, t_link **stack_b,
			t_score *best_score);
void	insert_sort(t_link **stack_a, t_link **stack_b);

/* ************************************************************************** */
/*    opti.c                                                                  */
/* ************************************************************************** */



#endif