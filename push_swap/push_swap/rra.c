/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:56:08 by kokim             #+#    #+#             */
/*   Updated: 2022/05/17 22:31:20 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack, int flag)
{
	t_node *tmp;

	if (stack->length < 2)
		return;
	tmp = stack->tail->prev;
	tmp->prev->next = stack->tail;
	stack->tail->prev = tmp->prev;
	stack->head->next->prev = tmp;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
	tmp->prev = stack->head;
	stack->top = tmp;
	if (flag == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int flag)
{
	t_node *tmp;

	if (stack->length < 2)
		return;
	tmp = stack->tail->prev;
	tmp->prev->next = stack->tail;
	stack->tail->prev = tmp->prev;
	stack->head->next->prev = tmp;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
	tmp->prev = stack->head;
	stack->top = tmp;
	if (flag == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	if (a->length < 2)
		return ;
	if (b->length < 2)
		return ;
	rra(a, 1);
	rrb(b, 1);
	write(1, "rrr\n", 4);
}