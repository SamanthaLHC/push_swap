/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:45:15 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/27 12:14:50 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link	*ft_lstnew_int(int nb)
{
	t_link	*new_elem;

	new_elem = malloc(sizeof(t_link));
	if (!new_elem)
		return (NULL);
	new_elem->nb = nb;
	new_elem->next = NULL;
	return (new_elem);
}

void	ft_link_back(t_link **alst, t_link *new)
{
	t_link	*last;

	if (*alst == NULL)
	{
		*alst = new;
	}	
	else
	{
		last = ft_link_last(*alst);
		last->next = new;
	}
}

t_link	*ft_link_last(t_link *lst)
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
