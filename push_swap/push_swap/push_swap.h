/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:57:06 by kokim             #+#    #+#             */
/*   Updated: 2022/05/17 22:33:48 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../library/printf/ft_printf.h"
# include <stdlib.h>
# define INT_MAX 2147483648
# define INT_MIN -2147483649

typedef struct	s_node
{
	int				data;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
} t_node;

typedef struct	s_stack
{
	t_node			*head;
	t_node			*tail;
	int				length;
	int				chunk;
	t_node			*top;
} t_stack;

/* ft_split.c */
char	**ft_split(char const *s, char c);
/* get_max.c */
int		get_max(t_stack *stack);
int		get_min(t_stack *stack);
int		get_max_index(t_stack *stack);
int		get_min_index(t_stack *stack);
/* sort_utils.c */
void	push_smallest_a(t_stack *a, t_stack *b);
/* sort_big.c */
void	sort_big(t_stack *a, t_stack *b);
/* check_argv.c */
void	push(t_stack *stack, int num, int index);
void	pop(t_stack *stack);
int		check_sorted(t_stack *a);
void	check_argv(int ac, char **av, t_stack *a, t_stack *b);
/* sort_upto_five.c */
void	sort_upto_five(t_stack *a, t_stack *b);
/* check_str.c */
void	check_str(char *str, t_stack *a, t_stack *b);
/* free_utils.c */
void	free_node(t_node *node);
void	free_stack(t_stack *stack);
void	remove_all(t_stack *stack);
void	exit_on_error(t_stack *a, t_stack *b);
void	show(t_stack *stack, char name);
/* array_utils.c */
void	array_converter(t_stack *a, int *arr);
/* instructions */
void	ra(t_stack *stack, int flag);
void	rb(t_stack *stack, int flag);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *stack, int flag);
void	rrb(t_stack *stack, int flag);
void	rrr(t_stack *a, t_stack *b);
void	sa(t_stack *stack, int flag);
void	sb(t_stack *stack, int flag);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *in, t_stack *out);
void	pb(t_stack *in, t_stack *out);
#endif
