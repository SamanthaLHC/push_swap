/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:31:44 by sam               #+#    #+#             */
/*   Updated: 2022/05/08 17:04:24 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	which_rotate_in_a(t_link **stack_a, t_way way)
{
	if (way == ROTATE)
		ft_ra(stack_a);
	else
		ft_rra(stack_a);
}

void	which_rotate_in_b(t_link **stack_b, t_way way)
{
	if (way == ROTATE)
		ft_rb(stack_b);
	else
		ft_rrb(stack_b);
}

void	rotate_stacks(t_link **stack_a, t_link **stack_b, t_score *score)
{
	while (*stack_b != score->pos_in_b && *stack_a != score->pos_in_a
		&& score->way_a == score->way_b)
	{
		if (score->way_a == ROTATE)
			ft_rr(stack_a, stack_b);
		if (score->way_a == ROT_REVERSE)
			ft_rrr(stack_a, stack_b);
	}	
	while (*stack_a != score->pos_in_a)
	{
		which_rotate_in_a(stack_a, score->way_a);
	}
	while (*stack_b != score->pos_in_b)
	{
		which_rotate_in_b(stack_b, score->way_b);
	}
}

void	insert_sort(t_link **stack_a, t_link **stack_b)
{
	t_score	score;

	if (count_elem_in_stack(*stack_a) > 1)
	{	
		ft_push_until_three(stack_a, stack_b);
		ft_sort_three(stack_a);
	}
	while (*stack_b)
	{
		select_elem_to_push(stack_a, stack_b, &score);
		rotate_stacks(stack_a, stack_b, &score);
		ft_pa(stack_b, stack_a);
	}
	score.pos_in_a = get_smallest(*stack_a);
	get_nb_move_and_way(score.pos_in_a, &score.way_a);
	while (*stack_a != score.pos_in_a)
	{
		which_rotate_in_a(stack_a, score.way_a);
	}
}
