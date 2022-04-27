/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:48:41 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/27 11:14:15 by sam              ###   ########.fr       */
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
		{
			ft_putstr_fd("Error\n", 2);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_duplicate(char *input)
{
	int	i;
	int	j;

	i = 1;
	j = i + 1;
	while (input[i])
	{
		while (input[j])
		{
			if (input[i] == input[j])
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int	ft_check_before_parsing(char *input, t_info *struct_info)
{
	int	err;

	err = 0;
	if (ft_input_is_digit(input) == -1)
		return (-1);
	if (ft_duplicate(input) == -1)
		return (-1);
	if (struct_info->stack_size == 1 || struct_info->stack_size == 0)
		return (-1);	
	ft_atoi(input, &err);
	if (err == -1)
		return (-1);	
	return (0);
}

//CHECK POUR PASSER LES ZEROS ??

//attention ligne vide