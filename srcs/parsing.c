/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 10:19:00 by sam               #+#    #+#             */
/*   Updated: 2022/04/21 16:04:00 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_element_from_input(char *input, t_list **list)
{
	int				err;
	int				*content;
	t_list			*new_elem;

	err = 0;
	new_elem = NULL;
	content = malloc(sizeof(*content));
	if (!content)
		return (-1);
	*content = ft_atoi(input, &err);
	new_elem = ft_lstnew(content);
	if (!new_elem)
		return (-1);
	ft_lstadd_back(list, new_elem);
	return (0);
}
