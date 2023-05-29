/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordinamento_cinque.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:12:21 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 16:12:22 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_smart_rotate(t_stack *stack, int n)
{
	int	k;

	k = 0;
	while (stack->stack_a[k] != n)
		k++;
	if (k >= stack->size_a / 2)
	{
		while (n != stack->stack_a[stack->size_a - 1])
			ft_rotate_wrt(stack, 'A');
	}
	if (k < stack->size_a / 2)
	{
		while (n != stack->stack_a[stack->size_a - 1])
			ft_rev_rotate_wrt(stack, 'A');
	}
}

void	ft_ordinamento_cinque(t_stack *stack)
{
	int	min;
	int	max;

	min = ft_find_max_min(stack->stack_a, stack->size_a, -1);
	max = ft_find_max_min(stack->stack_a, stack->size_a, 1);
	if (ft_in_testa(stack->stack_a, max, stack->size_a) == 0)
	{
		while (ft_in_testa(stack->stack_a, max, stack->size_a) == 0)
			ft_smart_rotate(stack, max);
	}
	ft_push_wrt(&stack, 'B');
	if (ft_in_testa(stack->stack_a, min, stack->size_a) == 0)
	{
		while (ft_in_testa(stack->stack_a, min, stack->size_a) == 0)
			ft_smart_rotate(stack, min);
	}
	ft_push_wrt(&stack, 'B');
	ft_ordinamento_tre(stack);
	ft_push_wrt(&stack, 'A');
	ft_push_wrt(&stack, 'A');
	ft_rotate_wrt(stack, 'A');
}
