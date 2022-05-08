/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 13:12:17 by sam               #+#    #+#             */
/*   Updated: 2022/05/08 14:36:04 by sam              ###   ########.fr       */
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

//fonction qui utilise get_nb and way pour 
// lui dire pour un elem specifique de b combie de move et quelle rot
// recup la pos d insertion dans a et combien de move et quel sens dans a et b
// dertermine un score pour determiner l insertion de b dans a
void	select_elem_to_push(t_link **stack_a, t_link **stack_b,
	t_score *best_score)
{
	t_score	score;

	best_score->pos_in_a = NULL;
	best_score->pos_in_b = NULL;
	best_score->moves_a = count_elem_in_stack(*stack_a) + 1;
	best_score->moves_b = count_elem_in_stack(*stack_b) + 1;
	best_score->way_a = ROTATE;
	best_score->way_b = ROTATE;
	score.pos_in_b = *stack_b;
	while (score.pos_in_b)
	{
		score.pos_in_a = get_insert_pos(*stack_a, score.pos_in_b->nb);
		score.moves_a = get_nb_move_and_way(score.pos_in_a, &score.way_a);
		score.moves_b = get_nb_move_and_way(score.pos_in_b, &score.way_b);
		if ((score.moves_a + score.moves_b)
			< (best_score->moves_a + best_score->moves_b))
		{
			ft_memcpy(best_score, &score, sizeof(score));
		}
		score.pos_in_b = score.pos_in_b->next;
	}
}
