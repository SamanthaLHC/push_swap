/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_handle_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:10:25 by sam               #+#    #+#             */
/*   Updated: 2022/05/02 17:43:56 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link	*ft_get_last(t_link *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_free_list(t_link *linked_list)
{
	t_link	*tmp;

	tmp = linked_list;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		free(linked_list);
		linked_list = tmp;
	}
}

int	count_elem_in_stack(t_link *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	ft_list_sort(t_link **stack, t_info *struct_info)
{
	t_link	*cmp;
	int		tmp;

	cmp = *stack;
	while (cmp->next)
	{
		if (cmp->nb > cmp->next->nb)
		{
			tmp = cmp->nb;
			cmp->nb = cmp->next->nb;
			cmp->next->nb = tmp;
			cmp = *stack;
		}
		cmp = cmp->next;
	}
	if (struct_info->stack_size > 1)
	{
		ft_list_sort(stack, struct_info->stack_size - 1);
	}
}
