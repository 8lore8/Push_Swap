/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:18:15 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:18:17 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chk_push_swap.h"

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
