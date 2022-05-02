/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:26:33 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/02 14:18:51 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// PRE SORT BEFORE SETING AN INDEX






/*
void	ft_algo(t_link **stack_a, t_link **stack_b)
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
			ft swap / rotate etc
		cmp = cmp->next;
	}
	cmp = *stack_a;

	
 on tente une mediane pour identifier un pivot plus pratique qui repartira
 mieux les deux stacks
*/