/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:12:17 by sam               #+#    #+#             */
/*   Updated: 2022/05/08 14:51:01 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	else if (first > mid && first > last)
		ft_ra(stack);
	else if (first > mid && first < last)
		ft_sa(stack);
	else if (first < mid && first > last)
		ft_rra(stack);
	else if (first < mid && mid > last)
	{
		ft_rra(stack);
		ft_sa(stack);
	}
}

t_link	*get_smallest(t_link *stack)
{
	t_link	*cmp_iter;
	t_link	*smallest;

	smallest = stack;
	cmp_iter = stack->next;
	while (cmp_iter)
	{
		if ((smallest)->nb > cmp_iter->nb)
			smallest = cmp_iter;
		cmp_iter = cmp_iter->next;
	}
	return (smallest);
}

t_link	*get_insert_pos(t_link *stack_a, int elem)
{
	t_link	*smallest;
	t_link	*pos;

	smallest = get_smallest(stack_a);
	pos = smallest;
	while (pos && pos->nb < elem)
	{
		pos = pos->next;
	}
	if (pos == NULL)
	{	
		pos = stack_a;
		while (pos != smallest && pos->nb < elem)
		{
			pos = pos->next;
		}
	}
	return (pos);
}

int	get_nb_move_and_way(t_link	*pos, t_way *way)
{
	t_link	*iter;
	int		count;
	int		nb_move;

	count = 0;
	nb_move = 0;
	iter = pos;
	while (iter)
	{
		iter = iter->next;
		count ++;
	}
	iter = pos;
	while (iter)
	{
		iter = iter->prev;
		nb_move ++;
	}
	*way = ROTATE;
	if (nb_move > count)
	{
		*way = ROT_REVERSE;
		nb_move = count;
	}
	return (nb_move);
}
