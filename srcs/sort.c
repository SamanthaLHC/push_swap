/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:26:33 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/05 15:53:34 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_save_ro(t_link *r_o, t_link **s_src, t_link **s_buf, int src_is_a)
{
	t_link	*last_keep;

	last_keep = r_o->prev;
	while (last_keep->next != NULL)
	{
		if (which_rr(s_buf, !src_is_a) == -1)
			return (-1);
		if (which_push(s_buf, s_src, !src_is_a) == -1)
			return (-1);
	}
	return (0);
}

int	ft_restore_ro(t_link **s_src, t_link **s_buf, int src_is_a,
	t_link *save_last_ro)
{
	while (!save_last_ro)
	{
		if (which_push(s_src, s_buf, src_is_a) == -1)
			return (-1);
		if (which_rr(s_buf, !src_is_a) == -1)
			return (-1);
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
	t_link	*save_last_ro;

	r_o = *stack_buf;
	if (ft_is_sorted(*stack_src) == -1)
	{
		if (ft_split_pivot(stack_src, stack_buf, src_is_a) == -1)
			return (0);
		if (ft_quick_sort(stack_src, stack_buf, src_is_a) == -1)
			return (-1);
		save_last_ro = ft_get_last(*stack_buf);
		if (ft_save_ro(r_o, stack_src, stack_buf, !src_is_a) == -1)
			return (-1);
		if (ft_quick_sort(stack_buf, stack_src, !src_is_a) == -1)
			return (-1);
		if (ft_restore_ro(stack_src, stack_buf, !src_is_a, save_last_ro) == -1)
			return (-1);
	//TODO
	// ICI MERGE LES DEUX STACKS TRIEES
	}
	return (0);
}

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
