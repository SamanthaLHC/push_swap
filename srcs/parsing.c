/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:19:00 by sam               #+#    #+#             */
/*   Updated: 2022/04/28 17:22:04 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_element_from_input(char *input, t_link **linked_list)
{
	int			err;
	int			nb;
	t_link		*new_elem;

	err = 0;
	new_elem = NULL;
	nb = ft_atoi(input, &err);
	new_elem = ft_lstnew_int(nb);
	if (!new_elem)
		return (-1);
	ft_link_back(linked_list, new_elem);
	return (0);
}

/*
int	ft_sort_stack(t_link **stack)
{
	t_link	*cmp;

	cmp = *stack;
	if (count_elem_in_stack(*stack) == 1 || count_elem_in_stack(*stack) == 0)
		return (-1);
	while (cmp)
	{
		if (cmp->nb < cmp->next->nb)
		{
			cmp = cmp->next;
			if (cmp->nb < stack->nb)
				ft_link_front(stack, cmp);
			ft_insert_in_sort(cmp);
		}
		//cmp = *stack;
		cmp = cmp->next;
	}
	return (0);
}
*/