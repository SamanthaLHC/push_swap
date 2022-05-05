/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:53:33 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/05 16:10:20 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_link **stack)
{
	t_link	*first;
	t_link	*last;

	first = *stack;
	*stack = (*stack)->next;
	last = ft_get_last(*stack);
	last->next = first;
	first->next = NULL;
	first->prev = last;
	(*stack)->prev = NULL;
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

int	which_rotate(t_link **stack, int src_is_a)
{
	if (src_is_a)
	{
		if (ft_ra(stack) == -1)
			return (-1);
	}
	else
	{
		if (ft_rb(stack) == -1)
			return (-1);
	}
	return (0);
}
