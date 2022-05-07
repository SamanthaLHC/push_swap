/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:12:17 by sam               #+#    #+#             */
/*   Updated: 2022/05/07 19:03:28 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_link *stack)
{
	while (stack && stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort_three(t_link **stack)
{
	int	first;
	int	mid;
	int	last;

	first = (*stack)->nb;
	mid = (*stack)->next->nb;
	last = ft_get_last(*stack)->nb;

	if (first > mid && mid > last)
	{
		ft_ra(stack);
		ft_sa(stack);
	}
	else if (first > mid && mid < last)
		ft_ra(stack);
	else if (first > mid && mid < last)
		ft_sa(stack);
	else if (first < mid && mid > last)
		ft_rra(stack);
	else if (first < mid && first < last)
	{
		ft_rra(stack);
		ft_sa(stack);
	}
}
