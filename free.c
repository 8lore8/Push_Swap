/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:11:36 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:11:38 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_free_stack_str(char **str, t_stack *stack)
{
	ft_free_str(str);
	free(stack);
	exit(0);
}

void	ft_free_stack_a_b(t_stack **stack)
{
	free((*stack)->stack_a);
	free((*stack)->stack_b);
	free(*stack);
	exit(0);
}

void	ft_free_nodi(t_punteggi **punteggi)
{
	t_punteggi	*tmp_p;
	t_mosse		*tmp_m;

	tmp_p = *punteggi;
	while (tmp_p)
	{
		if (tmp_p->mosse)
		{
			tmp_m = tmp_p->mosse;
			while (tmp_m)
			{
				if (tmp_m->str)
					free(tmp_m->str);
				tmp_m = tmp_m->next;
				free(tmp_p->mosse);
				tmp_p->mosse = tmp_m;
			}
		}
		tmp_p = tmp_p->next;
		free(*punteggi);
		*punteggi = tmp_p;
	}
}
