/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 12:58:19 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/25 00:04:43 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
carefull: need cast *(int*) for content because of the func's param
void *content 	
 */
void	print_arg(t_list *list)
{
	while (list)
	{
		ft_printf("%d\n", *(int *)list->content);
		list = list->next;
	}
}

void	free_elem_in_list(t_list *list)
{
	t_list	*tmp;

	tmp = list->next;
	while (list)
	{
		free(list->content);
		free(list);
	}
}

int	main(int ac, char **av)
{
	int				i;
	t_list			*list;

	list = NULL;
	i = 1;
	if (ac < 2)
		return (-1);
// faire une fonction check_and_parse??
	while (i < ac)
	{
		if (ft_check_before_parsing(av[i]) == -1)
			return (-1);
		get_element_from_input(av[i], &list);
		i++;
	}
	ft_duplicate(list);
	if (ft_sa(&list) == -1)
		return (-1);
	//^^^^^^^^^
	print_arg(list);
	free_elem_in_list(list);

	return (0);
}
