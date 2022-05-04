/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:26:33 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/04 23:42:17 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_link *stack)
{
	while (stack && stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (-1);
		stack = stack->next;
	}
	return (0);
}

int	ft_split_pivot(t_link **stack_src, t_link **stack_buf, int src_is_a)
{
	t_link	*pivot;

	pivot = ft_get_last(*stack_src);
	while (*stack_src && *stack_src != pivot)
	{
		if ((*stack_src)->nb < pivot->nb)
		{	
			if (which_push(stack_src, stack_buf, src_is_a) == -1)
				return (-1);
		}
		else
		{
			if (which_rotate(stack_src, src_is_a) == -1)
				return (-1);
		}
	}
	return (0);
}

int	ft_quick_sort(t_link **stack_src, t_link **stack_buf, int src_is_a)
{
	t_link	*r_o;

	r_o = *stack_buf;
	if (ft_split_pivot(stack_src, stack_buf, src_is_a) == -1)
		return (-1);
	if (ft_quick_sort(stack_src, stack_buf, src_is_a) == -1)
		return (-1);
//	ft_save_ro();
//	ft_quick_sort(buf, src, !src_is_a);
//	ft_restore_ro();
	return (0);
}

// gerer le tri par la recursion inpiree de quick sort

//identifier quelle stack a le role de temporary storage

// idee opti:

// fonction test si tous les elems sont > a pivot faire un rr
// a la place de la boucle du quick sort

// trouver le moyen d identifier les elements deja tries ou deja push

// il y aura une serie de nb ""read only""

// which is le plus petit inclure dans la val de retour d une fonction 
//qui permet d identifief si la stack est cyclement trie?

// si pivot elem plus grand que tous les elem : rr + push
// changer de stack

// faire un check pour choisir la meilleure strategie en therme de moov

// check si l elem s insert dans une stack deja cycliquement triee
