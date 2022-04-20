/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:48:41 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/15 18:02:27 by sle-huec         ###   ########.fr       */
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
			ft_printf("Error\n");
			return (-1);
		}
		i++;
	}
	return (0);
}
/*
int	ft_is_int(char *input)
{
	int	i;

	i = 0;
	if (input[i] == '0')
		i++;
	if (input[i] == '-' || input[i] == '+')
	{
		i++;
		if (input[i] == '0')
			i++;
		if (ft_strlen(input) > 10)
		{
			ft_printf("Error\n");
			return (-1);
		}
	}
}

int	ft_duplicate(char *input)
{
	int i;

	i = 0;
}
int	ft_errors(char *input)
{
	if (ft_input_is_digit(input) == -1)
	{
		ft_printf("Error\n");
		return (-1);
	}
	//if (ft_duplicate(input) == -1)
	//{
	//	ft_printf("Error\n");
	//	return (-1);
	//}
	//if (ft_is_int(input) == -1)
	//{
	//	ft_printf("Error\n");
	//	return (-1);
	//}	
	return (0);
}
//*/