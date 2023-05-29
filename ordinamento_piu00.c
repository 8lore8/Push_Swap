/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordinamento_piu00.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:14:20 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:14:21 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_punteggi_lista(t_stack **stack)
{
	t_punteggi	*punteggi;
	t_punteggi	*new_nodo_punteggi;
	int			i;

	i = (*stack)->size_a - 1;
	punteggi = NULL;
	while (i >= 0)
	{
		new_nodo_punteggi = ft_new_nodo_punteggi(*stack, i);
		ft_mosse_lista(*stack, &new_nodo_punteggi, i);
		ft_nodo_calcolo_punteggio(new_nodo_punteggi, new_nodo_punteggi->mosse);
		ft_addback_nodo_punteggi(&punteggi, new_nodo_punteggi);
		i--;
	}
	ft_scelta_nodo_esecuzione(punteggi, stack);
	ft_free_nodi(&punteggi);
}

void	ft_scelta_nodo_esecuzione(t_punteggi *punteggi, t_stack **stack)
{
	t_mosse	*tmp;

	tmp = NULL;
	ft_nodo_punti_minore(punteggi, &tmp);
	ft_esecuzione_mosse(*stack, tmp);
}
