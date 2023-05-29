/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_utils00.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:19:06 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:19:08 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chk_push_swap.h"

void	ft_separa_av(char *av1, t_stack *stack)
{
	char	**str;

	str = ft_split(av1, ' ');
	ft_checks(str, 'v', stack);
	stack->size_a = ft_conta_av (av1, ' ');
	stack->size_b = 0;
	stack->stack_a = malloc (sizeof(int) * stack->size_a);
	stack->stack_b = malloc (sizeof(int) * stack->size_a);
	ft_popola_stack_a(stack, str, 'v');
	ft_free_str(str);
	ft_controlli(stack);
}

void	ft_separa_ac(int ac, char **av, t_stack *stack)
{
	char	**str;

	str = ft_matrice_dup(ac, av);
	ft_checks(str, 'c', stack);
	stack->size_a = ac - 1;
	stack->size_b = 0;
	stack->stack_a = malloc (sizeof(int) * stack->size_a);
	stack->stack_b = malloc (sizeof(int) * stack->size_a);
	ft_popola_stack_a(stack, str, 'c');
	ft_free_str(str);
	ft_controlli(stack);
}

static long int	conversione(const char *nptr)
{
	long int	i;
	long int	j;

	j = 0;
	i = 0;
	while (((char *)nptr)[i] != '\0')
	{
		if (((char *)nptr)[i] >= '0' && ((char *)nptr)[i] <= '9')
			j = j * 10 + (((char *)nptr)[i] - '0');
		else
			return (j);
		i++;
	}
	return (j);
}

long int	ft_long_atoi(const char *nptr)
{
	long int	i;
	long int	j;
	long int	s;

	i = 0;
	j = 0;
	s = 1;
	while ((((char *)nptr)[i] >= '\t' && ((char *)nptr)[i] <= '\r')
			|| ((char *)nptr)[i] == 32)
		i++;
	if (((char *)nptr)[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (((char *)nptr)[i] == '+')
		i++;
	j = conversione(&((char *)nptr)[i]);
	return (j * s);
}
