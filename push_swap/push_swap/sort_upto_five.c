/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_upto_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:46:03 by kokim             #+#    #+#             */
/*   Updated: 2022/05/17 00:56:45 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *stack)
{
	if (check_sorted(stack))
		return ;
	t_node	*tmp;

	tmp = stack->top;
	if (tmp->data > tmp->next->data)
		sa(stack, 0);
}

static void	sort_three(t_stack *a)
{
	int	max_idx;
	
	if (check_sorted(a))
		return ;
	max_idx = get_max_index(a);
	if (a->top->index == max_idx)
		ra(a, 0);
	else if (a->top->next->index == max_idx)
		rra(a, 0);
	if (a->top->index == max_idx - 1)
		sa(a, 0);
}

static void	sort_four(t_stack *a, t_stack *b)
{
	push_smallest_a(a, b);
	sort_three(a);
	pa(a, b);
}

static void	sort_five(t_stack *a, t_stack *b)
{
	push_smallest_a(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	sort_upto_five(t_stack *a, t_stack *b)
{
	if (a->length == 2)
		sort_two(a);
	else if (a->length == 3)
		sort_three(a);
	else if (a->length == 4)
		sort_four(a, b);
	else if (a->length == 5)
		sort_five(a, b);
	else
		return ;
}