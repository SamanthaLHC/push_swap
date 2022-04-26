/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 18:45:15 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/25 18:47:14 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_struct_info(t_struct_info *struct_info)
{
	struct_info->stack_size = 0;
}

t_list	*ft_lstnew_int(int content)
{
	struct s_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}
