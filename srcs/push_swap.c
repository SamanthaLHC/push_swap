/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:58:19 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/03 14:15:47 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TEST
void	print_arg(t_link *list)
{
	while (list)
	{
		ft_printf("%d\n", list->nb);
		list = list->next;
	}
}

//TODO
//Mettre sort param et set index dans parsing.c 

/*
void	ft_sort_params(char **av, int ac)
{
	int	temp;
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (i < ac - 1)
	{
		if (av[i] > av[j])
		{	
			temp = av[i];
			av[i] = av[j];
			av[j] = temp;
		}
		i++;
		j++;
	}
	if (ac > 1)
	{
		ft_sort_params(av, ac - 1);
	}
}
*/

/*
void	ft_set_index(t_link **stack_a)
{
	t_link	*iter;
		
	iter = *stack_a;
	(*stack_a)->idx = 0;
	while (iter)
	{
		iter = iter->next;
		(*stack_a)->idx++;
	}
}
*/

int	main(int ac, char **av)
{

	//TODO
	//Faire une fonction check_and_parse dans parsing.c qui check, pre-sort, 
	//set index et save dans list chainee
	
	int		i;
	t_link	*stack_a;
	//TODO
	t_link	*stack_b;
	t_info	struct_info;

	stack_a = NULL;
	//TODO
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
	i = 1;	
		
	//TEST
	
	if (ft_pb(&stack_a, &stack_b) == -1)
		return (-1);
	print_arg(stack_a);
	ft_printf("stack_b:\n");
	print_arg(stack_b);
/*
	if (ft_sa(&stack_a) == -1)
		return (-1);
	print_arg(stack_a);
	print_arg(stack_b);

	if (ft_ra(&stack_a) == -1)
		return (-1);
	print_arg(stack_a);
	print_arg(stack_b);
	
	if (ft_rra(&stack_a) == -1)
		return (-1);
	print_arg(stack_a);
	print_arg(stack_b);
	*/
	
	ft_free_list(stack_a);
	//TODO
	ft_free_list(stack_b);

	return (0);
}
