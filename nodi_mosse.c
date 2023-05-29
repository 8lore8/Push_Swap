/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodi_mosse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:12:42 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:12:44 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*--CREA NODO MOSSE---------------------------------------------------------->*/
t_mosse	*ft_new_nodo_mosse(char *str)
{
	t_mosse	*new_nodo;

	new_nodo = (t_mosse *)malloc(sizeof(t_mosse));
	if (!new_nodo)
		return (NULL);
	new_nodo->str = (char *)malloc(sizeof(char) * 4);
	if (!new_nodo->str)
		return (NULL);
	if (str)
		ft_strlcpy(new_nodo->str, str, 4);
	new_nodo->next = NULL;
	return (new_nodo);
}

/*--RITORNA ULTIMO NODO MOSSE------------------------------------------------>*/
t_mosse	*ft_last_nodo_mosse(t_mosse *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*--AGGIUNGI ALL'ULTIMO NODO MOSSE------------------------------------------->*/
void	ft_addback_nodo_mosse(t_mosse **lst, t_mosse *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_last_nodo_mosse(*lst)->next = new;
}
