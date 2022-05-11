/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:11:44 by kokim             #+#    #+#             */
/*   Updated: 2022/05/11 22:40:56 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void move_biggest_a(t_stack *stack)
{
	int index;
	t_node *tmp;

	index = get_max(stack);
	tmp = stack->top;
	while (tmp != stack->tail)
	{
		if (tmp->index == index)
		{
			if (tmp->index >= (stack->length) / 2)
			{
				while (tmp->next != stack->tail)
					rotate_stack(stack, 'A');
			}
			if (tmp->index < (stack->length) / 2)
			{
				while (tmp->next != stack->tail)
					reverse_rotate_stack(stack, 'A');
			}
			return;
		}
		tmp = tmp->next;
	}
}

void	move_all_to_b(t_stack *a, t_stack *b)
{
	t_node	*tmp;

	tmp = a->top;
	while (tmp != a->tail->prev)
	{
		push_stack(b, a, 'B');
		tmp = tmp->next;
	}
}

void	move_biggest_b(t_stack *stack)
{
	int index;
	t_node *tmp;

	index = get_max(stack);
	tmp = stack->top;
	while (tmp != stack->tail)
	{
		if (tmp->index == index)
		{
			if (tmp->index <= (stack->length) / 2)
			{
				while (tmp->prev != stack->head)
					rotate_stack(stack, 'A');
			}
			if (tmp->index > (stack->length) / 2)
			{
				while (tmp->prev != stack->head)
					reverse_rotate_stack(stack, 'A');
			}
			return;
		}
		tmp = tmp->next;
	}
}

void sort_a_b(t_stack *a, t_stack *b)
{
	/* 최대값 a 밑으로 */
	move_biggest_a(a);
	/* 최대값 제외하고 전부 b로 넘기기 */
	move_all_to_b(a, b);
	/* b에서 최대값 찾아서 맨 위로 올리기 */
	while (b->head->next != b->tail)
	{
		move_biggest_b(b);
		push_stack(a, b, 'A');
	}
}