/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:26:33 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/05 17:32:55 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_save_ro(t_link *r_o, t_link **s_src, t_link **s_buf, int src_is_a)
{
	t_link	*last_keep;
	ft_printf("r_o->prev->nb: %d\n", r_o->prev->nb);

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
	//debugg
	ft_printf("bonjour je suis la variable pivot et je vaux: %d\n", pivot->nb);
	while (*stack_src && *stack_src != pivot)
	{
		ft_printf("split en cours dans le while\n");
		print_arg(*stack_src);
		print_arg(*stack_buf);
		
		if ((*stack_src)->nb < pivot->nb)
		{	
			if (which_push(stack_src, stack_buf, src_is_a) == -1)
				return (-1);
			print_arg(*stack_src);
			print_arg(*stack_buf);
		}
		else
		{
			if (which_rotate(stack_src, src_is_a) == -1)
				return (-1);
			print_arg(*stack_src);
			print_arg(*stack_buf);
		}
	}
	return (0);
}

int	ft_quick_sort(t_link **stack_src, t_link **stack_buf, int src_is_a, int call)
{
	t_link	*r_o;
	t_link	*save_last_ro;

	r_o = *stack_buf;
	//DEBUGG
	printf("call : %d\n src_is_a:%d\n", call, src_is_a);
	
	if (ft_is_sorted(*stack_src) == -1)
	{
		//debugg
		ft_printf("not sorted\n");
		if (ft_split_pivot(stack_src, stack_buf, src_is_a) == -1)
		{
			//debugg
			ft_printf("split fini\n");
			return (0);
		}
		// est ce checke si c est trie ??? 
		
		if (ft_quick_sort(stack_src, stack_buf, src_is_a, call + 1) == -1)
		{
			//debugg
			ft_printf("deuxieme appel quick sort\n");
			print_arg(*stack_src);
			print_arg(*stack_buf);
			return (-1);
		}
		if (r_o != *stack_buf)
		{
			ft_printf("problem is here\n");
			save_last_ro = ft_get_last(*stack_buf);
			ft_printf("bonjour je suis la variable save_last_ro et je vaux : %d\n", save_last_ro->nb);
			if (ft_save_ro(r_o, stack_src, stack_buf, !src_is_a) == -1)
				return (-1);
			if (ft_quick_sort(stack_buf, stack_src, !src_is_a, call + 1) == -1)
				return (-1);
			if (ft_restore_ro(stack_src, stack_buf, !src_is_a, save_last_ro) == -1)
				return (-1);
		}
	//TODO
	// ICI MERGEr LES DEUX STACKS TRIEES
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
