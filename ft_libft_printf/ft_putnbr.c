/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:17:41 by sle-huec          #+#    #+#             */
/*   Updated: 2022/01/06 15:46:35 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_printf.h"

int	static	ft_counting(int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	if (n == 0)
		count ++;
	while (n != 0)
	{
		n /= 10;
		count ++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar('-');
		num = n * -1;
	}
	else
		num = n;
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
	return (ft_counting(n));
}
