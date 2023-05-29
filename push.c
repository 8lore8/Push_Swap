/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:15:33 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:15:35 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_mov(t_stack **stack, char x)
{
	int	dim_a;
	int	dim_b;

	dim_a = (*stack)->size_a;
	dim_b = (*stack)->size_b;
	if (x == 'A')
	{
		if ((*stack)->size_b == 0)
			return ;
		(*stack)->stack_a[dim_a] = (*stack)->stack_b[dim_b - 1];
		(*stack)->size_a += 1;
		(*stack)->size_b -= 1;
	}
	else if (x == 'B')
	{
		if ((*stack)->size_a == 0)
			return ;
		(*stack)->stack_b[dim_b] = (*stack)->stack_a[dim_a - 1];
		(*stack)->size_b += 1;
		(*stack)->size_a -= 1;
	}
}

void	ft_push_wrt(t_stack **stack, char x)
{
	if (x == 'A')
	{
		ft_push_mov(&(*stack), 'A');
		ft_printf("pa\n");
	}
	else if (x == 'B')
	{
		ft_push_mov(&(*stack), 'B');
		ft_printf("pb\n");
	}
}
