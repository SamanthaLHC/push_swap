/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:26:33 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/06 00:17:53 by sam              ###   ########.fr       */
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
	while (save_last_ro != ft_get_last(*s_buf))
	{
		if (which_push(s_src, s_buf, src_is_a) == -1)
			return (-1);
		if (which_rotate(s_buf, !src_is_a) == -1)
			return (-1);
	}
	return (0);
}

int	ft_split_pivot(t_link **stack_src, t_link **stack_buf, int src_is_a)
{
	//convention boolean commence par is is_src_a
	t_link	*pivot;

	pivot = ft_get_last(*stack_src);
	//debugg
	ft_printf("pivot: %d\n", pivot->nb);
	while (*stack_src && *stack_src != pivot)
	{
		//debugg
		/*
		ft_printf("split en cours\n");
		ft_printf("stack_src:\n");
		print_arg(*stack_src);
		ft_printf("stack_buf:\n");
		print_arg(*stack_buf);
		*/
		if ((*stack_src)->nb < pivot->nb)
		{	
			//push_to_right_stack
			if (which_push(stack_src, stack_buf, src_is_a) == -1)
				return (-1);
			//debugg
		/*	ft_printf("stack_src:\n");
			print_arg(*stack_src);
			ft_printf("stack_buf:\n");
			print_arg(*stack_buf);
		*/}
		else
		{
			if (which_rotate(stack_src, src_is_a) == -1)
				return (-1);
			//debugg
		/*	ft_printf("stack_src:\n");
			print_arg(*stack_src);
			ft_printf("stack_buf:\n");
			print_arg(*stack_buf);
		*/}
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
	ft_printf("Avant Sort Check %c (%d): save_last_ro=%d\n", src_is_a ? 'A' : 'B', call, ft_get_last(*stack_buf) ? ft_get_last(*stack_buf)->nb : -1);

	
	if (ft_is_sorted(*stack_src) == 0)
		return (0);
		//debugg
	ft_printf("not sorted, ro=%d\n", r_o ? r_o->nb : -1);
	if (ft_split_pivot(stack_src, stack_buf, src_is_a) == -1)
	{
		//debugg
		ft_printf("split fini\n");
		return (0);
	}
	ft_printf("Apres pivot %c (%d): save_last_ro=%d\n", src_is_a ? 'A' : 'B', call, ft_get_last(*stack_buf) ? ft_get_last(*stack_buf)->nb : -1);
	ft_printf("stack_src:\n");
	print_arg(*stack_src);
	ft_printf("stack_buf:\n");
	print_arg(*stack_buf);
	// est ce checke si c est trie ??? 
	//
	//r_o = *stack_buf;
	if (ft_quick_sort(stack_src, stack_buf, src_is_a, call + 1) == -1)
	{
		//debugg
		ft_printf("deuxieme appel quick sort\n");
	/*  ft_printf("stack_src:\n");
		print_arg(*stack_src);
		ft_printf("stack_buf:\n");
		print_arg(*stack_buf);
	*/	return (-1);
	}
	ft_printf("Apres recursion %c (%d): save_last_ro=%d\n", src_is_a ? 'A' : 'B', call, ft_get_last(*stack_buf) ? ft_get_last(*stack_buf)->nb : -1);

	if (r_o != *stack_buf)
	{
		save_last_ro = ft_get_last(*stack_buf);
		ft_printf("variable save_last_ro : %d\n", save_last_ro ? save_last_ro->nb : -1);
		ft_printf("variable ro : %d\n", r_o ? r_o->nb : -1);
		ft_printf("stack_src:\n");
		print_arg(*stack_src);
		ft_printf("stack_buf:\n");
		print_arg(*stack_buf);
		
		if (r_o != NULL 
			&& ft_save_ro(r_o, stack_src, stack_buf, !src_is_a) == -1)
			return (-1);
		
		ft_printf("save les elem deja trie (ro)\n");
		ft_printf("on change la stack source\n");
		ft_printf("stack_src(buf in next call):\n");
		print_arg(*stack_src);
		ft_printf("stack_buf(src in next call):\n");
		print_arg(*stack_buf);
		if (ft_quick_sort(stack_buf, stack_src, !src_is_a, call + 1) == -1)
		{
			ft_printf("[%d]Save second recursion returned -1\n", call);
			return (-1);
		}
		if (r_o != NULL && ft_restore_ro(stack_src, stack_buf,
				!src_is_a, save_last_ro) == -1)
		{
			ft_printf("[%d] Restore ro returned -1\n", call);
			return (-1);
		}
		ft_printf("Supposed to have restored %d to %d\n", r_o ? r_o->nb : -1, save_last_ro ? save_last_ro->nb : -1);
		print_arg(*stack_buf);
		
		// ICI MERGEr LES DEUX STACKS TRIEES
		// PSEUDO CODE
		t_link *last_keep;

		if (r_o != NULL)
			last_keep = r_o->prev;
		else
			last_keep = ft_get_last(*stack_buf);
			
		if (last_keep)
		{
			t_link	*first_keep;

			first_keep = *stack_buf;
			ft_printf("first_keep=%d last_keep=%d\n", first_keep->nb, last_keep->nb);
			while (last_keep != *stack_buf)
			{
				if (which_rotate(stack_buf, !src_is_a) == -1)
					return (-1);
			}
			while (first_keep != *stack_buf)
			{
				if (which_push(stack_buf, stack_src, !src_is_a) == -1)
					return (-1);
				if (which_rr(stack_buf, !src_is_a) == -1)
					return (-1);
			}
			if (which_push(stack_buf, stack_src, !src_is_a) == -1)
				return (-1);
			
		}
		ft_printf("Merged split stack:\nstack_src:\n");
		print_arg(*stack_src);
		ft_printf("stack_buf:\n");
		print_arg(*stack_buf);
		
	}
	//TODO
	
	

	ft_printf("pop: return dans l appel d avant: call %d\n", call - 1);
	return (0);
}

//TODO
	// ICI MERGEr LES DEUX STACKS TRIEES


	
// idee opti:

// fonction test si tous les elems sont > a pivot faire un rr
// a la place de la boucle du quick sort

// trouver le moyen d identifier les elements deja tries ou deja push

// which is le plus petit inclure dans la val de retour d une fonction 
//qui permet d identifie si la stack est cycliquement trie?

// si pivot elem plus grand que tous les elem : rr + push
// changer de stack

// faire un check pour choisir la meilleure strategie en therme de moov

// check si l elem s insert dans une stack deja cycliquement triee
