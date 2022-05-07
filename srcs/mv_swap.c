/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:26:38 by sam               #+#    #+#             */
/*   Updated: 2022/05/07 13:09:22 by sam              ###   ########.fr       */
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

void	ft_sa(t_link **stack_a)
{
	ft_swap(stack_a);
	ft_printf("sa\n");
}

void	ft_sb(t_link **stack_b)
{
	ft_swap(stack_b);
	ft_printf("sb\n");
}

void	ft_ss(t_link **stack_a, t_link **stack_b)
{	
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}

/*
int	which_swap(t_link **stack, int src_is_a)
{
	if (src_is_a)
	{
		if (ft_sa(stack) == -1)
			return (-1);
	}
	else
	{
		if (ft_sb(stack) == -1)
			return (-1);
	}
	return (0);
}
*/