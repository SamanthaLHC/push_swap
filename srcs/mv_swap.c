/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:26:38 by sam               #+#    #+#             */
/*   Updated: 2022/05/04 23:18:06 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_link **stack)
{
	t_link	*tmp_head;

	tmp_head = *stack;
	*stack = (*stack)->next;
	tmp_head->next = (*stack)->next;
	(*stack)->next = tmp_head;
	tmp_head->prev = *stack;
	(*stack)->prev = NULL;
}

int	ft_sa(t_link **stack_a)
{
	if (count_elem_in_stack(*stack_a) == 1
		|| count_elem_in_stack(*stack_a) == 0)
		return (-1);
	ft_swap(stack_a);
	ft_printf("sa\n");
	return (0);
}

int	ft_sb(t_link **stack_b)
{
	if (count_elem_in_stack(*stack_b) == 1
		|| count_elem_in_stack(*stack_b) == 0)
		return (-1);
	ft_swap(stack_b);
	ft_printf("sb\n");
	return (0);
}
// check elem's numbers? v

int	ft_ss(t_link **stack_a, t_link **stack_b)
{
	if (count_elem_in_stack(*stack_a) == 1
		|| count_elem_in_stack(*stack_a) == 0
		|| count_elem_in_stack(*stack_b) == 1
		|| count_elem_in_stack(*stack_b) == 0)
		return (-1);
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
	return (0);
}

int	which_swap(t_link **stack, int src_is_a)
{
	if (src_is_a)
	{
		if (ft_sb(stack) == -1)
			return (-1);
	}
	else
	{
		if (ft_sa(stack) == -1)
			return (-1);
	}
	return (0);
}
