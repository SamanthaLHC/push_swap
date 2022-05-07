/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:35:09 by sam               #+#    #+#             */
/*   Updated: 2022/05/07 13:07:26 by sam              ###   ########.fr       */
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

/*
int	which_push(t_link **stack_src, t_link **stack_buf, int src_is_a)
{
	if (src_is_a)
	{
		if (ft_pb(stack_src, stack_buf) == -1)
			return (-1);
	}
	else
	{
		if (ft_pa(stack_src, stack_buf) == -1)
			return (-1);
	}
	return (0);
}
*/