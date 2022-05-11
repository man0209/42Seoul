/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 22:02:51 by kokim             #+#    #+#             */
/*   Updated: 2022/05/06 00:03:08 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack *stack)
{
	int		max;
	int		index;
	t_node	*top;

	top = stack->top;
	max = top->data;
	index = top->index;
	while (top != stack->tail)
	{
		if (top->data > max)
		{
			max = top->data;
			index = top->index;
		}
		top = top->next;
	}
	return (index);
}

int	get_min(t_stack *stack)
{
	int		min;
	int		index;
	t_node	*top;

	top = stack->top;
	min = top->data;
	index = top->index;
	while (top != stack->tail)
	{
		if (min > top->data)
		{
			min = top->data;
			index = top->index;
		}
		top = top->next;
	}
	return (index);
}

void	move_smallest_a(t_stack *a, t_stack *b)
{
	int		index;
	t_node	*tmp;

	index = get_min(a);
	tmp = a->top;
	while (tmp != a->tail)
	{
		if (tmp->index == index)
		{
			if (tmp->index >= (a->length) / 2)
			{
				while (tmp->prev != a->head)
					rotate_stack(a, 'A');
				push_stack(b, a, 'B');
			}
			if (tmp->index < (a->length) / 2)
			{
				while (tmp->prev != a->head)
					reverse_rotate_stack(a, 'A');
				push_stack(b, a, 'B');
			}
			return ;
		}
		tmp = tmp->next;
	}
}