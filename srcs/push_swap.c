/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:58:19 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/15 17:53:52 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 2)
		return (-1);
	while (i < ac)
	{
		if (ft_input_is_digit(av[i]) == -1)
		{
			return (-1);
		}
		ft_printf("coucou%d\n", atoi(av[i]));
		ft_printf("pouet%d\n", ft_atoi(av[i]));
		i++;
	}
	return (0);
}
