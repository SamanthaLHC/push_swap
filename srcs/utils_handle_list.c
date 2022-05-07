/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_handle_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:10:25 by sam               #+#    #+#             */
/*   Updated: 2022/05/07 13:14:07 by sam              ###   ########.fr       */
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

void	print_arg(t_link *list)
{
	while (list)
	{
		ft_printf("%d\n", list->nb);
		list = list->next;
	}
}
