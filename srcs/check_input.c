/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:48:41 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/24 21:19:10 by sam              ###   ########.fr       */
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

int	ft_duplicate(t_list *list)
{
	t_list	*tmp_iter;

	while (list)
	{
		tmp_iter = list->next;
		while (tmp_iter)
		{
			if (*(int *)list->content == *(int *)tmp_iter->content)
			{
				ft_putstr_fd("Error\n", 2);
				return (-1);
			}
			tmp_iter = tmp_iter->next;
		}
		list = list->next;
	}
	return (0);
}

int	ft_check_before_parsing(char *input)
{
	int	err;

	err = 0;
	if (ft_input_is_digit(input) == -1)
		return (-1);
	ft_atoi(input, &err);
	if (err == -1)
		return (-1);
	return (0);
}

// need check guillemets ??? 

int	count_elem_in_pile(t_list *pile)
{
	int	i;

	i = 0;
	while (pile)
	{
		i++;
		pile = pile->next;
	}
	if (i == 1 || i == 0)
		return (-1);
	return (0);
}
