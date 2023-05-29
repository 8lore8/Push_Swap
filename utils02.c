/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils02.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:16:36 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:16:37 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_args(char *str)
{
	int		i;
	int		sign_count;
	int		digit_count;

	i = 0;
	sign_count = 0;
	digit_count = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1 && (str[i + 1] == '-' || str[i + 1] == '+'))
			return (0);
		if (ft_isdigit(str[i]) == 0 && str[i] != '+' && str[i] != '-')
			return (0);
		if (str[i] == '+' || str[i] == '-')
			sign_count++;
		else
			digit_count++;
		i++;
	}
	if (digit_count == 0 || sign_count > 1)
		return (0);
	return (1);
}

int	ft_check_min_max(char *str)
{
	long int	x;

	x = ft_atoi_long(str);
	if (x > INT_MAX || x < INT_MIN)
		return (0);
	return (1);
}

int	ft_check_double(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a)
	{
		j = i + 1;
		while (j < stack->size_a)
		{
			if (stack->stack_a[i] == stack->stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}		

int	ft_check_order(t_stack *stack)
{
	int	i;

	i = 1;
	while (i < stack->size_a)
	{
		if (stack->stack_a[i] > stack->stack_a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

long int	ft_atoi_long(const char *nptr)
{
	long			res;
	long			sign;
	unsigned int	i;

	res = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' || \
			nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10 + nptr[i] - '0');
		i++;
	}
	return (res * sign);
}
