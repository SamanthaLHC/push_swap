/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:26:38 by sam               #+#    #+#             */
/*   Updated: 2022/04/27 11:30:34 by sam              ###   ########.fr       */
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
}

int	ft_sa(t_link **stack_a, t_info *struct_info)
{
	if (struct_info->stack_size == -1)
		return (-1);
	ft_swap(stack_a);
	ft_printf("sa\n");
	return (0);
}

int	ft_sb(t_link **stack_b, t_info *struct_info)
{
	if (struct_info->stack_size == -1)
		return (-1);
	ft_swap(stack_b);
	ft_printf("sb\n");
	return (0);
}
// check elem's numbers? v

void	ft_ss(t_link **stack_a, t_link **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	ft_printf("ss\n");
}
