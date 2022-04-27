/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:35:09 by sam               #+#    #+#             */
/*   Updated: 2022/04/27 19:19:49 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_link **stack_src, t_link **stack_dst)
{
	t_link	*new_head_src;

	new_head_src = (*stack_src)->next;
	ft_link_front(stack_dst, *stack_src);
	*stack_src = new_head_src;
}

int	ft_pa(t_link **stack_b, t_link **stack_a)
{
	if (count_elem_in_stack(*stack_b) == 0)
		return (-1);
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
	return (0);
}

int	ft_pb(t_link **stack_a, t_link **stack_b)
{
	if (count_elem_in_stack(*stack_a) == 0)
		return (-1);
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
	return (0);
}

