/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 22:47:12 by kokim             #+#    #+#             */
/*   Updated: 2022/05/16 23:03:03 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack, int flag)
{
	t_node *tmp;

	if (stack->length < 2)
		return;
	tmp = stack->top;
	stack->head->next = tmp->next;
	tmp->next->prev = stack->head;
	tmp->next = stack->tail;
	tmp->prev = stack->tail->prev;
	stack->tail->prev->next = tmp;
	stack->tail->prev = tmp;
	stack->top = stack->head->next;
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int flag)
{
	t_node *tmp;

	if (stack->length < 2)
		return;
	tmp = stack->top;
	stack->head->next = tmp->next;
	tmp->next->prev = stack->head;
	tmp->next = stack->tail;
	tmp->prev = stack->tail->prev;
	stack->tail->prev->next = tmp;
	stack->tail->prev = tmp;
	stack->top = stack->head->next;
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	if (a->length < 2)
		return ;
	if (b->length < 2)
		return ;
	ra(a, 1);
	rb(b, 1);
	write(1, "rr\n", 3);
}