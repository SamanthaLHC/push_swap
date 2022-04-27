/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:58:19 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/27 12:15:33 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//test et debugg
void	print_arg(t_link *list)
{
	while (list)
	{
		ft_printf("%d\n", list->nb);
		list = list->next;
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_link	*linked_list;
	t_info	struct_info;

	linked_list = NULL;
	i = 1;
	struct_info.stack_size = ac -1;
	if (ac < 2)
		return (-1);
	while (i < ac)
	{
		if (ft_check_before_parsing(av[i], &struct_info) == -1)
			return (-1);
		get_element_from_input(av[i], &linked_list);
		i++;
	}
	if (ft_sa(&linked_list, &struct_info) == -1)
		return (-1);
	//^^^^^^^^^
	print_arg(linked_list);
	ft_free_list(linked_list);
	return (0);
}
