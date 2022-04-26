/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:58:19 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/25 18:32:52 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//test et debugg
void	print_arg(t_list *list)
{
	while (list)
	{
		ft_printf("%d\n", *(int *)list->content);
		list = list->next;
	}
}

int	main(int ac, char **av)
{
	int				i;
	t_linked_list	*linked_list;
	t_struct_info	*struct_info;

	linked_list = NULL;
	struct_info = NULL;
	i = 1;
	init_struct_info(struct_info);
	struct_info->stack_size = ac;
	if (ac < 2)
		return (-1);
	while (i < ac)
	{
		if (ft_check_before_parsing(av[i]) == -1)
			return (-1);
		get_element_from_input(av[i], &linked_list);
		i++;
	}
	if (ft_sa(&linked_list) == -1)
		return (-1);
	//^^^^^^^^^
	print_arg(linked_list);
	return (0);
}
