/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodi_punteggi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:14:12 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:14:13 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*--CREA NODO PUNTEGGI------------------------------------------------------->*/
t_punteggi	*ft_new_nodo_punteggi(t_stack *stack, int i)
{
	t_punteggi	*new_nodo;

	new_nodo = (t_punteggi *)malloc(sizeof(t_punteggi));
	if (!new_nodo)
		return (NULL);
	new_nodo->punti = 0;
	new_nodo->num = stack->stack_a[i];
	new_nodo->mosse = NULL;
	new_nodo->next = NULL;
	return (new_nodo);
}

/*--RITORNA ULTIMO NODO PUNTEGGI--------------------------------------------->*/
t_punteggi	*ft_last_nodo_punteggi(t_punteggi *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*--AGGIUNGI ALL'ULTIMO NODO PUNTEGGI---------------------------------------->*/
void	ft_addback_nodo_punteggi(t_punteggi **lst, t_punteggi *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_last_nodo_punteggi(*lst)->next = new;
}

/*--CALCOLO PUNTEGGIO MOSSE ------------------------------------------------->*/
void	ft_nodo_calcolo_punteggio(t_punteggi *new_nodo_punteggi, t_mosse *mosse)
{
	int	i;

	i = 0;
	while (mosse)
	{
		mosse = mosse->next;
		i++;
	}
	new_nodo_punteggi->punti = i;
}
