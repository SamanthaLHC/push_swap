/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:49:38 by sam               #+#    #+#             */
/*   Updated: 2022/04/27 19:20:29 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_link **stack)
{
	t_link	*last;

	last = ft_get_last(*stack);
	ft_link_front(stack, last);
	while (last->next != *stack)
	{
		last = last->next;
	}
	last->next = NULL;
}

int	ft_rra(t_link **stack_a)
{
	if (count_elem_in_stack(*stack_a) == -1
		|| count_elem_in_stack(*stack_a) == 0)
		return (-1);
	ft_reverse_rotate(stack_a);
	ft_printf("rra\n");
	return (0);
}

int	ft_rrb(t_link **stack_b)
{
	if (count_elem_in_stack(*stack_b) == -1
		|| count_elem_in_stack(*stack_b) == 0)
		return (-1);
	ft_reverse_rotate(stack_b);
	ft_printf("rrb\n");
	return (0);
}

int	ft_rrr(t_link **stack_a, t_link **stack_b)
{
	if (count_elem_in_stack(*stack_a) == -1
		|| count_elem_in_stack(*stack_a) == 0
		|| count_elem_in_stack(*stack_b) == -1
		|| count_elem_in_stack(*stack_b) == 0)
		return (-1);
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_printf("rrr\n");
	return (0);
}