/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:35:09 by sam               #+#    #+#             */
/*   Updated: 2022/05/10 19:06:32 by sle-huec         ###   ########.fr       */
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

void	ft_pa(t_link **stack_b, t_link **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	ft_pb(t_link **stack_a, t_link **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	ft_push_until_three(t_link **stack_a, t_link **stack_b)
{
	while (count_elem_in_stack(*stack_a) > 3)
	{
		ft_pb(stack_a, stack_b);
	}
}
