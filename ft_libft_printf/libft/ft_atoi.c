/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sle-huec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:23:25 by sle-huec          #+#    #+#             */
/*   Updated: 2021/12/03 16:49:03 by sle-huec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_atoi(const char *nptr)
{
	int		i;
	int		result;
	int		neg_or_pos;
	char	*str;

	str = (char *)nptr;
	i = 0;
	result = 0;
	neg_or_pos = 1;
	while ((str[i] && str[i] >= 9 && str[i] <= 13) || str[i] == 32)
	{	
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg_or_pos = -neg_or_pos;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * neg_or_pos);
}
/*
#include <stdlib.h>
#include <stdio.h>
int main()
{
	printf("%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n
	%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
			atoi("-2"),
			ft_atoi("-2"),
			atoi("g678"),
			ft_atoi("g678"),
			atoi("   4"),
			ft_atoi("   4"),
			atoi(" 56"),
			ft_atoi(" 56"),
			atoi("+56jihyuyr"),
			ft_atoi("+56jihyuyr"),
			atoi("iuioyouy"),
			ft_atoi("iuioyouy"),
			atoi("2147483647"),
			ft_atoi("2147483647"),
			atoi("2147483648"),
			ft_atoi("2147483648"),
			atoi("-2147483648"),
			ft_atoi("-2147483648"),
			atoi("0"),
			ft_atoi("0"),
			atoi(""),
			ft_atoi(""),
			atoi("                78"),
			ft_atoi("                78"),
			atoi("++2"),
			ft_atoi("++2"),
			atoi("--2"),
			ft_atoi("--2"));
}
*/
