/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:05:34 by sle-huec          #+#    #+#             */
/*   Updated: 2022/04/24 22:10:14 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

/* ************************************************************************** */
/*    check_input.c                                                           */
/* ************************************************************************** */

int		ft_check_before_parsing(char *input);
int		ft_input_is_digit(char *input);
int		ft_duplicate(t_list *list);
int		count_elem_in_pile(t_list *pile);

/* ************************************************************************** */
/*    parsing.c                                                               */
/* ************************************************************************** */

int		get_element_from_input(char *input, t_list **list);

/* ************************************************************************** */
/*    mv_swap.c                                                               */
/* ************************************************************************** */

void	ft_swap(t_list **pile);
int		ft_sa(t_list **pile_a);
int		ft_sb(t_list **pile_b);
void	ft_ss(t_list **pile_a, t_list **pile_b);

#endif