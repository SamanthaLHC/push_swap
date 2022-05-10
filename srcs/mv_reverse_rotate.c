/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 13:49:38 by sam               #+#    #+#             */
/*   Updated: 2022/05/10 19:06:40 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//le dernier devient le premier 

void	ft_reverse_rotate(t_link **stack)
{
	t_link	*last;

	last = ft_get_last(*stack);
	if (!last->prev)
		return ;
	last->prev->next = NULL;
	ft_link_front(stack, last);
}

void	ft_rra(t_link **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	ft_rrb(t_link **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_link **stack_a, t_link **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	ft_printf("rrr\n");
}

/*s
int	which_rr(t_link **stack, int src_is_a)
{
	if (src_is_a)
	{
		if (ft_rra(stack) == -1)
			return (-1);
	}
	else
	{
		if (ft_rrb(stack) == -1)
			return (-1);
	}
	return (0);
}
*/