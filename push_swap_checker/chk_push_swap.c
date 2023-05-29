/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:18:31 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:18:32 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chk_push_swap.h"

void	esegui_mosse(t_stack *stack)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		ft_muovi(stack, str);
		free(str);
		str = get_next_line(0);
	}
}

void	ft_muovi_continue(t_stack *stack, char *str)
{
	if (ft_strncmp(str, "rr\n", 3) == 0)
		ft_rotate_wrt(stack, 'R');
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		ft_rev_rotate_wrt(stack, 'A');
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		ft_rev_rotate_wrt(stack, 'B');
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		ft_rev_rotate_wrt(stack, 'R');
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		ft_push_wrt(&stack, 'B');
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		ft_push_wrt(&stack, 'A');
	else
	{
		ft_putstr_fd("Error\n", 2);
		free(str);
		get_next_line(-42);
		ft_free_stack_a_b(&stack);
	}
}

void	ft_muovi(t_stack *stack, char *str)
{
	if (ft_strncmp(str, "sa\n", 3) == 0)
		ft_swap_wrt(stack, 'A');
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		ft_swap_wrt(stack, 'B');
	else if (ft_strncmp(str, "ss\n", 3) == 0)
	{
		ft_swap_wrt(stack, 'A');
		ft_swap_wrt(stack, 'B');
	}
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ft_rotate_wrt(stack, 'A');
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		ft_rotate_wrt(stack, 'B');
	else
		ft_muovi_continue(stack, str);
}

int	main(int ac, char **av)
{
	t_stack	*stack;

	if (ac == 1)
		return (0);
	stack = malloc(sizeof(t_stack));
	if (ac == 2)
		ft_separa_av(av[1], stack);
	if (ac > 2)
		ft_separa_ac(ac, av, stack);
	esegui_mosse(stack);
	if (ft_check_order(stack) == 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	ft_free_stack_a_b(&stack);
	return (0);
}
