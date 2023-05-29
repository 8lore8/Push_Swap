/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:16:31 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:16:32 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checks(char **str, char x, t_stack *stack)
{
	int	i;

	i = 0;
	if (x == 'v')
		i = 0;
	else if (x == 'c')
		i = 1;
	while (str[i])
	{
		if (ft_check_args(str[i]) != 1)
		{
			ft_printf("Error\n");
			ft_free_stack_str(str, stack);
		}
		else if (ft_check_min_max(str[i]) != 1)
		{
			ft_printf("Error\n");
			ft_free_stack_str(str, stack);
		}
		i++;
	}
	return (1);
}

int	ft_conta_av(char const *av1, char c)
{
	int	count;
	int	i;
	int	a;

	count = 0;
	i = 0;
	a = 0;
	while (av1[i])
	{
		if (av1[i] != c && a == 0)
		{
			count++;
			a = 1;
		}
		else if (av1[i] == c)
			a = 0;
		i++;
	}
	return (count);
}

void	ft_popola_stack_a(t_stack *stack, char **str, char x)
{
	int	i;
	int	j;

	i = 0;
	if (x == 'v')
	{
		j = stack->size_a - 1;
		while (j >= 0)
			stack->stack_a[i++] = ft_atoi(str[j--]);
	}
	else if (x == 'c')
	{
		j = stack->size_a;
		while (j > 0)
			stack->stack_a[i++] = ft_atoi(str[j--]);
	}
}

void	ft_controlli(t_stack *stack)
{
	if (ft_check_double(stack) == 1)
	{
		ft_printf("Error\n");
		ft_free_stack_a_b(&stack);
	}
	if (ft_check_order(stack) == 1)
	{
		ft_free_stack_a_b(&stack);
	}
}

char	**ft_matrice_dup(int ac, char **av)
{
	int			i;
	char		**matrice;

	i = 0;
	matrice = malloc(sizeof(char *) * (ac + 1));
	if (!matrice)
		return (NULL);
	while (i < ac)
	{
		matrice[i] = ft_strdup(av[i]);
		i++;
	}
	matrice[i] = NULL;
	return (matrice);
}
