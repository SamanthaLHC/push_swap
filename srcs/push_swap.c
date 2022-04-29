/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:58:19 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/29 14:21:33 by sle-huec         ###   ########.fr       */
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
	t_link	*stack_a;
	//t_link	*stack_b;
	t_info	struct_info;

	stack_a = NULL;
	//stack_b = NULL;
	i = 1;
	struct_info.stack_size = ac -1;
	if (ac < 2)
		return (-1);
	while (i < ac)
	{
		if (ft_check_before_parsing(av[i], &struct_info) == -1)
			return (-1);
		get_element_from_input(av[i], &stack_a);
		i++;
	}
	/*
	if (ft_pb(&stack_a, &stack_b) == -1)
		return (-1);
	print_arg(stack_a);
	print_arg(stack_b);
	*/
	ft_free_list(stack_a);
	//ft_free_list(stack_b);

	return (0);
}
