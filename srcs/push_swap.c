/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:58:19 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/10 19:07:00 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_and_parse(int ac, char **input, t_link **stack_a)
{
	int		i;
	t_info	struct_info;

	i = 1;
	struct_info.stack_size = ac -1;
	while (i < ac)
	{
		if (ft_check_before_parsing(input[i], &struct_info) == -1)
			return (-1);
		i++;
	}
	i = 1;
	while (i < ac)
	{
		get_element_from_input(input[i], stack_a);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_link	*stack_a;
	t_link	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (-1);
	if (check_and_parse(ac, av, &stack_a))
		return (-1);
	if (ft_duplicate(stack_a) == -1)
	{
		ft_free_list(stack_a);
		ft_free_list(stack_b);
		return (-1);
	}
	if (!ft_is_sorted(stack_a))
		insert_sort(&stack_a, &stack_b);
	ft_free_list(stack_a);
	ft_free_list(stack_b);
	return (0);
}
