/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:26:33 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/01 18:12:29 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "push_swap.h"

void	ft_sort(t_link **stack_a, t_link **stack_b)
{
	t_link	*pivot;
	t_link	*cmp;

	pivot = ft_get_last(*stack_a);
	cmp = *stack_a;

******QUIK SORT*****
Une premiere boucle dans l'input(stak_a) pour creer deux stack a partir d un pivot
pivot defini arbitrairement sur le last


	while (cmp)
	{
		if (cmp->nb < pivot->nb)
			ft_pb(stack_a, stack_b);
		cmp = cmp->next;
	}
	cmp = *stack_a;
}

 on tente une mediane pour identifier un pivo plus pratique qui repartira
 mieux les deux stacks
*/