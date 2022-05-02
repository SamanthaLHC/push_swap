/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_add_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:45:15 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/02 23:06:22 by sam              ###   ########.fr       */
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
	new_elem->prev = NULL;
	return (new_elem);
}

void	ft_link_back(t_link **alst, t_link *new)
{
	t_link	*last;

	if (*alst == NULL)
	{
		*alst = new;
		new->next = NULL;
		new->prev = NULL;
	}	
	else
	{
		last = ft_get_last(*alst);
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}

void	ft_link_front(t_link **alst, t_link *new)
{
	new->next = *alst;
	new->prev = NULL;
	*alst = new;
	new->next->prev = new;
}
