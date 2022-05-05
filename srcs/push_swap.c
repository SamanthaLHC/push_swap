/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:58:19 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/05 20:15:08 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TEST


int	main(int ac, char **av)
{
	int		i;
	t_link	*stack_a;
	t_link	*stack_b;
	t_info	struct_info;

	stack_a = NULL;
	stack_b = NULL;
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
	if (ft_duplicate(stack_a) == -1)
		return (-1);
	ft_quick_sort(&stack_a, &stack_b, 1, 1);
	// ICI merge stack(val de retour ptr sur la stack_a)
	//TEST
	
	print_arg(stack_a);
	ft_printf("stack_b:\n");
	print_arg(stack_b);
	
	ft_free_list(stack_a);
	ft_free_list(stack_b);
	return (0);
}
