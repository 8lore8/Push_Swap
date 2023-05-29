/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:16:05 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:16:07 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_mov_a(t_stack *stack)
{
	int		*tmp;
	int		i;

	if (!stack)
		return ;
	i = 0;
	tmp = malloc((sizeof(int)) * stack->size_a);
	while (i < stack->size_a)
	{
		tmp[i] = stack->stack_a[i];
		i++;
	}
	stack->stack_a[0] = tmp[stack->size_a - 1];
	i = 1;
	while (i < stack->size_a)
	{
		stack->stack_a[i] = tmp [i - 1];
		i++;
	}
	free(tmp);
}

void	ft_rotate_mov_b(t_stack *stack)
{
	int		*tmp;
	int		i;

	if (!stack)
		return ;
	i = 0;
	tmp = malloc((sizeof(int)) * stack->size_b);
	while (i < stack->size_b)
	{
		tmp[i] = stack->stack_b[i];
		i++;
	}
	stack->stack_b[0] = tmp[stack->size_b - 1];
	i = 1;
	while (i < stack->size_b)
	{
		stack->stack_b[i] = tmp [i - 1];
		i++;
	}
	free(tmp);
}

void	ft_rotate_wrt(t_stack *stack, char x)
{
	if (x == 'A')
	{
		ft_rotate_mov_a(stack);
		ft_printf("ra\n");
	}
	else if (x == 'B')
	{
		ft_rotate_mov_b(stack);
		ft_printf("rb\n");
	}
	else if (x == 'R')
	{
		ft_rotate_mov_a(stack);
		ft_rotate_mov_b(stack);
		ft_printf("rr\n");
	}
}
