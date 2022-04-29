/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:53:33 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/29 14:23:36 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_link **stack)
{
	t_link	*first;

	first = *stack;
	*stack = (*stack)->next;
	ft_get_last(*stack)->next = first;
	first->next = NULL;
}

int	ft_ra(t_link **stack_a)
{
	if (count_elem_in_stack(*stack_a) == 1
		|| count_elem_in_stack(*stack_a) == 0)
		return (-1);
	ft_rotate(stack_a);
	ft_printf("ra\n");
	return (0);
}

int	ft_rb(t_link **stack_b)
{
	if (count_elem_in_stack(*stack_b) == 1
		|| count_elem_in_stack(*stack_b) == 0)
		return (-1);
	ft_rotate(stack_b);
	ft_printf("rb\n");
	return (0);
}

int	ft_rr(t_link **stack_a, t_link **stack_b)
{
	if (count_elem_in_stack(*stack_a) == 1
		|| count_elem_in_stack(*stack_a) == 0
		|| count_elem_in_stack(*stack_b) == 1
		|| count_elem_in_stack(*stack_b) == 0)
		return (-1);
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
	return (0);
}
