/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordinamento_utils01.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:15:23 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:15:25 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
	{
		if (i < n - 1)
			i++;
		else
			return (0);
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

int	ft_size_lst(t_mosse *lst)
{
	int		i;
	t_mosse	*fun;

	if (!lst)
		return (0);
	i = 1;
	fun = lst;
	while (fun->next != NULL)
	{
		fun = fun->next;
		i++;
	}
	return (i);
}

int	ft_optimized(t_mosse *mosse)
{
	int	num;

	num = ft_size_lst(mosse);
	ft_printf("num: %d	// ", num);
	return (num);
}

int	ft_sostituzione(t_mosse *mosse, char *str)
{
	while (mosse != NULL)
	{
		if (ft_strncmp(mosse->str, str, 3) == 0)
		{
			if (ft_strncmp(str, "RA ", 3) == 0)
			{
				ft_strlcpy(mosse->str, "RR ", 4);
				return (0);
			}
			if (ft_strncmp(str, "RRA", 3) == 0)
			{
				ft_strlcpy(mosse->str, "RRR", 4);
				return (0);
			}
		}
		mosse = mosse->next;
	}
	return (1);
}

void	ft_esecuzione_mosse(t_stack *stack, t_mosse *tmp)
{
	while (tmp)
	{
		if (ft_strncmp(tmp->str, "RA ", 3) == 0)
			ft_rotate_wrt(stack, 'A');
		if (ft_strncmp(tmp->str, "RB ", 3) == 0)
			ft_rotate_wrt(stack, 'B');
		if (ft_strncmp(tmp->str, "RR ", 3) == 0)
			ft_rotate_wrt(stack, 'R');
		if (ft_strncmp(tmp->str, "RRA", 3) == 0)
			ft_rev_rotate_wrt(stack, 'A');
		if (ft_strncmp(tmp->str, "RRB", 3) == 0)
			ft_rev_rotate_wrt(stack, 'B');
		if (ft_strncmp(tmp->str, "RRR", 3) == 0)
			ft_rev_rotate_wrt(stack, 'R');
		if (ft_strncmp(tmp->str, "PB ", 3) == 0)
			ft_push_wrt(&stack, 'B');
		tmp = tmp->next;
	}
}
