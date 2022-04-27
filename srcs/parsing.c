/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:19:00 by sam               #+#    #+#             */
/*   Updated: 2022/04/27 11:28:17 by sam              ###   ########.fr       */
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

// convertir les arg en index avec les content du plus petit au plus grand 
// avec 