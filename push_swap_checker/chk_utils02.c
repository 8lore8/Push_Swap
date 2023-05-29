/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_utils02.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:19:16 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:19:17 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chk_push_swap.h"

int	ft_check_args(char *str)
{
	int		i;
	int		sign_count;
	int		digit_count;

	i = 0;
	sign_count = 0;
	digit_count = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		sign_count++;
		i++;
	}
	while (str[i])
	{
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

	x = ft_long_atoi(str);
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
	if (stack->size_b > 0)
		return (0);
	while (i < stack->size_a)
	{
		if (stack->stack_a[i] > stack->stack_a[i - 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < n - 1)
			i++;
		else
			return (0);
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
