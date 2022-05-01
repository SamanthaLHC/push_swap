/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:48:41 by sle-huec          #+#    #+#             */
/*   Updated: 2022/05/01 19:44:45 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_input_is_digit(char *input)
{
	int	i;

	i = 0;
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
	if (struct_info->stack_size == 1 || struct_info->stack_size == 0)
		return (-1);
	ft_atoi(input, &err);
	if (err == -1)
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

//TODO
//CHECK POUR PASSER LES ZEROS
//attention ligne vide