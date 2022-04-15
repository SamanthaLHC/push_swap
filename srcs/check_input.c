/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 11:48:41 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/15 15:06:16 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"





int ft_errors(char *input)
{
	if(ft_is_digit(input) == -1)
	{

		return(-1);
	}
	if(ft_is_int(input) == -1)
	{

		return(-1);
	}
	if(ft_duplicate(input) == -1)
	{
		ft_printf()
		return(-1);
	}
	
}