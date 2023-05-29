/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordinamento_piu01.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:14:26 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:14:27 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mosse_scrittura(t_mosse **mosse, char *str)
{
	t_mosse	*new_nodo_mosse;

	new_nodo_mosse = ft_new_nodo_mosse(str);
	ft_addback_nodo_mosse(mosse, new_nodo_mosse);
}

void	ft_mosse_check(char stack, char *str1, char *str2, t_mosse **mosse)
{
	if (stack == 'A')
		ft_mosse_scrittura(mosse, str1);
	else
	{
		if (!(ft_sostituzione(*mosse, str1) == 0))
			ft_mosse_scrittura(mosse, str2);
	}
}

void	ft_mosse_testa(int size, int index, char stack, t_mosse **mosse)
{
	int	num_mosse;

	if (index >= (size / 2))
	{
		num_mosse = size - index;
		while (num_mosse-- > 0)
			ft_mosse_check(stack, "RA ", "RB ", mosse);
	}
	else
	{
		num_mosse = index + 1;
		while (num_mosse-- > 0)
			ft_mosse_check(stack, "RRA", "RRB", mosse);
	}
}

void	ft_mosse_lista(t_stack *stack, t_punteggi **punteggi, int i)
{
	int		maxb;
	int		minb;
	int		ndif;

	maxb = ft_find_max_min(stack->stack_b, stack->size_b, 1);
	minb = ft_find_max_min(stack->stack_b, stack->size_b, -1);
	ndif = ft_difettob(stack->stack_b, (*punteggi)->num, stack->size_b);
	if (i != stack->size_a - 1)
		ft_mosse_testa(stack->size_a - 1, i, 'A', &(*punteggi)->mosse);
	if (((*punteggi)->num > maxb) || ((*punteggi)->num < minb))
	{
		if (ft_in_testa(stack->stack_b, maxb, stack->size_b) == 0)
			ft_mosse_testa(stack->size_b - 1,
				ft_trova_difetto(stack->stack_b, maxb),
				'B', &(*punteggi)->mosse);
	}
	else
	{
		if (ft_in_testa(stack->stack_b, ndif, stack->size_b) == 0)
			ft_mosse_testa(stack->size_b - 1,
				ft_trova_difetto(stack->stack_b, ndif),
				'B', &(*punteggi)->mosse);
	}
	ft_mosse_scrittura(&(*punteggi)->mosse, "PB ");
}
