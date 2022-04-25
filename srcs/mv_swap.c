/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:26:38 by sam               #+#    #+#             */
/*   Updated: 2022/04/25 17:59:23 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// A MODIFIER AVEC LA MANIERE LISTE CHAINEE CIRCULAIRE 
void	ft_swap(t_list **pile)
{
	t_list	*tmp_head;

	tmp_head = *pile;
	*pile = (*pile)->next;
	tmp_head->next = (*pile)->next;
	(*pile)->next = tmp_head;
}

int	ft_sa(t_list **pile_a)
{
	if (count_elem_in_pile(*pile_a) == -1)
		return (-1);
	ft_swap(pile_a);
	ft_printf("sa\n");
	return (0);
}

int	ft_sb(t_list **pile_b)
{
	if (count_elem_in_pile(*pile_b) == -1)
		return (-1);
	ft_swap(pile_b);
	ft_printf("sb\n");
	return (0);
}
// check elem's numbers? v

void	ft_ss(t_list **pile_a, t_list **pile_b)
{
	ft_swap(pile_a);
	ft_swap(pile_b);
	ft_printf("ss\n");
}
