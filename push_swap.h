/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbaroni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 15:15:57 by lbaroni           #+#    #+#             */
/*   Updated: 2023/04/28 15:15:59 by lbaroni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

typedef struct s_mosse
{
	char			*str;
	struct s_mosse	*next;
}	t_mosse;

typedef struct s_punteggi
{
	int					punti;
	int					num;
	t_mosse				*mosse;
	struct s_punteggi	*next;
}	t_punteggi;

/* File PUSH_SWAP */
/*--------------------------------------------------------------------------->*/
void		ft_ordinamento_all(t_stack *stack);

/* File UTILS00 */
/*--------------------------------------------------------------------------->*/
void		ft_separa_av(char *av1, t_stack *stack);
void		ft_separa_ac(int ac, char **av, t_stack *stack);

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
long int	ft_atoi_long(const char *nptr);

/* File ORDINAMENTO_TRE */
/*--------------------------------------------------------------------------->*/
void		ft_ordinamento_tre(t_stack *stack);

/* File ORDINAMENTO_PIU_00*/
/*--------------------------------------------------------------------------->*/
void		ft_punteggi_lista(t_stack **stack);
void		ft_scelta_nodo_esecuzione(t_punteggi *punteggi, t_stack **stack);

/* File ORDINAMENTO_PIU_01*/
/*--------------------------------------------------------------------------->*/
void		ft_mosse_scrittura(t_mosse **mosse, char *str);
void		ft_mosse_check(char stack, char *str1, char *str2, t_mosse **mosse);
void		ft_mosse_testa(int size, int index, char stack, t_mosse **mosse);
void		ft_mosse_lista(t_stack *stack, t_punteggi **punteggi, int i);

/* File NODI_PUNTEGGI*/
/*--------------------------------------------------------------------------->*/
t_punteggi	*ft_new_nodo_punteggi( t_stack *stack, int i);
t_punteggi	*ft_last_nodo_punteggi(t_punteggi *lst);
void		ft_addback_nodo_punteggi(t_punteggi **lst, t_punteggi *new);
void		ft_nodo_calcolo_punteggio(t_punteggi *new_nodo, t_mosse *mosse);

/* File NODI_MOSSE*/
/*--------------------------------------------------------------------------->*/
t_mosse		*ft_new_nodo_mosse(char *str);
t_mosse		*ft_last_nodo_mosse(t_mosse *lst);
void		ft_addback_nodo_mosse(t_mosse **lst, t_mosse *new);

/* File ORINAMENTO_UTILS00*/
/*--------------------------------------------------------------------------->*/
int			ft_in_testa(int *stack, int n, int size);
int			ft_difettob(int *stackb, int num_a, int size);
int			ft_find_max_min(int *stack, int size, int maxmin);
int			ft_trova_difetto(int *stackb, int num);
void		ft_nodo_punti_minore(t_punteggi *punteggi, t_mosse **tmp);

/* File ORINAMENTO_UTILS01*/
/*--------------------------------------------------------------------------->*/
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_size_lst(t_mosse *lst);
int			ft_optimized(t_mosse *mosse);
int			ft_sostituzione(t_mosse *mosse, char *str);
void		ft_esecuzione_mosse(t_stack *stack, t_mosse *tmp);

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
void		ft_free_nodi(t_punteggi **punteggi);

/* File ORDINAMENTO_CINQUE */
/*--------------------------------------------------------------------------->*/
void		ft_smart_rotate(t_stack *stack, int n);
void		ft_ordinamento_cinque(t_stack *stack);
#endif
