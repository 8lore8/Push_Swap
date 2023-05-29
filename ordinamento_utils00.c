/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordinamento_utils00.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:15:15 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:15:17 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_in_testa(int *stack, int n, int size)
{
	if (n == stack[size - 1])
		return (1);
	else
		return (0);
}

int	ft_difettob(int *stackb, int num_a, int size)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = INT_MIN;
	while (i < size)
	{
		if (stackb[i] < num_a && stackb[i] > tmp)
			tmp = stackb[i];
		i++;
	}
	return (tmp);
}

int	ft_find_max_min(int *stack, int size, int maxmin)
{
	int	i;
	int	n;
	int	min;
	int	max;

	i = 1;
	n = 0;
	min = -1;
	max = 1;
	while (i < size)
	{
		if (maxmin == max)
		{
			if (stack[i] > stack[n])
				n = i;
		}
		else if (maxmin == min)
		{
			if (stack[i] < stack[n])
				n = i;
		}
		i++;
	}
	return (stack[n]);
}

int	ft_trova_difetto(int *stackb, int num)
{
	int	i;

	i = 0;
	while (stackb[i] != num)
		i++;
	return (i);
}

void	ft_nodo_punti_minore(t_punteggi *punteggi, t_mosse **tmp)
{
	int	i;

	i = punteggi->punti;
	*tmp = punteggi->mosse;
	while (punteggi)
	{
		if (punteggi->punti < i)
		{
			*tmp = punteggi->mosse;
			i = punteggi->punti;
		}
		punteggi = punteggi->next;
	}
}
