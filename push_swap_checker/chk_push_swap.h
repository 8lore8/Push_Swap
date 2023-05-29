/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:18:37 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:18:38 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHK_PUSH_SWAP_H
# define CHK_PUSH_SWAP_H

# include "./Libftcompleta/libft.h"
# include <limits.h>

/* Strutture STACK - MOSSE - PUNTEGGI */
/*--------------------------------------------------------------------------->*/
typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		size_b;
}		t_stack;

/* File PUSH_SWAP */
/*--------------------------------------------------------------------------->*/
void		ft_ordinamento_all(t_stack *stack);
void		ft_muovi(t_stack *stack, char *str);

/* File UTILS00 */
/*--------------------------------------------------------------------------->*/
void		ft_separa_av(char *av1, t_stack *stack);
void		ft_separa_ac(int ac, char **av, t_stack *stack);
long int	ft_long_atoi(const char *nptr);

/* File UTILS01 */
/*--------------------------------------------------------------------------->*/
int			ft_checks(char **str, char x, t_stack *stack);
int			ft_conta_av(char const *av1, char c);
void		ft_popola_stack_a(t_stack *stack, char **str, char x);
void		ft_controlli(t_stack *stack);
char		**ft_matrice_dup(int ac, char **av);

/* File UTILS02 */
/*--------------------------------------------------------------------------->*/
int			ft_check_args(char *str);
int			ft_check_min_max(char *str);
int			ft_check_double(t_stack *stack);
int			ft_check_order(t_stack *stack);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/* File SWAP */
/*--------------------------------------------------------------------------->*/
void		ft_swap_mov(t_stack *stack, char x);
void		ft_swap_wrt(t_stack *stack, char x);

/* File ROTATE e ROTATE_REV */
/*--------------------------------------------------------------------------->*/
void		ft_rotate_mov_a(t_stack *stack);
void		ft_rotate_mov_b(t_stack *stack);
void		ft_rotate_wrt(t_stack *stack, char x);

/* File ROTATE_REV */
/*--------------------------------------------------------------------------->*/
void		ft_rev_rotate_mov_a(t_stack *stack);
void		ft_rev_rotate_mov_b(t_stack *stack);
void		ft_rev_rotate_wrt(t_stack *stack, char x);

/* File PUSH */
/*--------------------------------------------------------------------------->*/
void		ft_push_mov(t_stack **stack, char x);
void		ft_push_wrt(t_stack **stack, char x);

/* File FREE*/
/*--------------------------------------------------------------------------->*/
void		ft_free_str(char **str);
void		ft_free_stack_str(char **str, t_stack *stack);
void		ft_free_stack_a_b(t_stack **stack);

#endif
