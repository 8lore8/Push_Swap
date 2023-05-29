/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordinamento_tre.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:15:08 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:15:09 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ordinamento_tre(t_stack *stack)
{
	int	uno;
	int	due;
	int	tre;

	uno = stack->stack_a[0];
	due = stack->stack_a[1];
	tre = stack->stack_a[2];
	if (uno > due && uno > tre && due < tre)
		ft_swap_wrt(stack, 'A');
	else if (uno < due && uno < tre && due < tre)
	{
		ft_swap_wrt(stack, 'A');
		ft_rev_rotate_wrt(stack, 'A');
	}
	else if (uno > due && uno < tre && due < tre)
		ft_rotate_wrt(stack, 'A');
	else if (uno < due && uno > tre && due > tre)
	{
		ft_swap_wrt(stack, 'A');
		ft_rotate_wrt(stack, 'A');
	}
	else if (uno < due && uno < tre && due > tre)
		ft_rev_rotate_wrt(stack, 'A');
}
