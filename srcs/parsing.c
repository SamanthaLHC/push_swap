/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:19:00 by sam               #+#    #+#             */
/*   Updated: 2022/05/10 19:06:55 by sle-huec         ###   ########.fr       */
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
