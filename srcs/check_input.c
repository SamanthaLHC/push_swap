/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:48:41 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/20 18:50:02 by sam              ###   ########.fr       */
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
int	ft_duplicate(char *input)
{
	int	i;

	i = 0;
}
*/
int	ft_check_before_parsing(char *input)
{
	int	err;

	err = 0;
	if (ft_input_is_digit(input) == -1)
		return (-1);
	ft_atoi(input, &err);
	if (err == -1)
	{
		return (-1);
	}
	return (0);
}
