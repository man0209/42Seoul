/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_upto_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:46:03 by kokim             #+#    #+#             */
/*   Updated: 2022/05/05 23:29:55 by kokim            ###   ########.fr       */
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
		swap_stack(stack, 'A');
}

static void	sort_three(t_stack *a)
{
	if (check_sorted(a))
		return ;
	if (a->top->index == get_min(a))
	{ 
		reverse_rotate_stack(a, 'A');
		swap_stack(a, 'A');
	}
	else if (a->top->index == get_max(a))
	{
		rotate_stack(a, 'A');
		if (a->top->index != get_min(a))
			swap_stack(a, 'A');
	}
	else
	{
		if (a->tail->prev->index == get_max(a))
			swap_stack(a, 'A');
		else
			reverse_rotate_stack(a, 'A');
	}
}

static void	sort_four(t_stack *a, t_stack *b)
{
	move_smallest_a(a, b);
	sort_three(a);
	push_stack(a, b, 'A');
}

static void	sort_five(t_stack *a, t_stack *b)
{
	move_smallest_a(a, b);
	sort_four(a, b);
	push_stack(a, b, 'A');
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