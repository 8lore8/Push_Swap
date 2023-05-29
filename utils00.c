/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:16:26 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:16:27 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
