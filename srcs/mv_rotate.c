/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:53:33 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/10 19:06:45 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//le premier devient le dernier

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

void	ft_ra(t_link **stack_a)
{
	ft_rotate(stack_a);
	ft_printf("ra\n");
}

void	ft_rb(t_link **stack_b)
{
	ft_rotate(stack_b);
	ft_printf("rb\n");
}

void	ft_rr(t_link **stack_a, t_link **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}

/*
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
*/