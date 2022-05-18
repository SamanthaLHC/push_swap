/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:06:20 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/18 12:06:01 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_input_is_digit(char *input)
{
	int	i;

	i = 0;
	if (!input)
		return (-1);
	if (input[0] == '\0')
		return (-1);
	while (input[i])
	{
		if (input[i] == '-')
			i++;
		if (ft_isdigit(input[i]) != 1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_check_before_parsing(char *input, t_info *struct_info)
{
	int	err;

	err = 0;
	if (ft_input_is_digit(input) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	ft_atoi(input, &err);
	if (err == -1)
		return (-1);
	if (struct_info->stack_size == 1 || struct_info->stack_size == 0)
		return (-1);
	return (0);
}

int	ft_duplicate(t_link *stack_a)
{
	t_link	*tmp_iter;

	while (stack_a)
	{
		tmp_iter = stack_a->next;
		while (tmp_iter)
		{
			if (stack_a->nb == tmp_iter->nb)
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
			tmp_iter = tmp_iter->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

	//TEST
/*
void	ft_test_moov(t_link **stack_a, t_link **stack_b)
{
	if (ft_pb(&stack_a, &stack_b) == -1)
		return (-1);
	print_arg(stack_a);
	ft_printf("stack_b:\n");
	print_arg(stack_b);

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
}
	*/
