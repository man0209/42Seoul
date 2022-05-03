/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:55:24 by kokim             #+#    #+#             */
/*   Updated: 2022/05/03 23:50:15 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack, char type)
{
	int		tmp_data;
	t_node	*tmp;
	
	if (stack == NULL)
		return ;
	if (type < 'A' || type > 'B')
		return ;
	tmp = stack->top;
	if (tmp->next == stack->tail)
		return ;
	tmp_data = stack->top->data;
	stack->top->data = stack->top->next->data;
	stack->top->next->data = tmp_data;
	if (type == 'A')
		printf("sa\n");
	else if (type == 'B')
		printf("sb\n");
}

void	push_stack(t_stack *in, t_stack *out, char type)
{
	int	data;

	if (in == NULL || out == NULL)
		return ;
	if (type < 'A' || type > 'B')
		return ;
	data = out->top->data;
	pop(out, out->top);
	push(in, data);
	if (type == 'A')
		printf("pa\n");
	else if (type == 'B')
		printf("pb\n");
}

void	rotate_stack(t_stack *stack, char type)
{
	t_node	*tmp;

	if (stack == NULL)
		return ;
	if (type < 'A' || type > 'B')
		return ;
	tmp = stack->top;
	stack->head->next = tmp->next;
	tmp->next->prev = stack->head;
	tmp->next = stack->tail;
	tmp->prev = stack->tail->prev;
	stack->tail->prev->next = tmp;
	stack->tail->prev = tmp;
	stack->top = stack->head->next;
	if (type == 'A')
		printf("ra\n");
	else if (type == 'B')
		printf("rb\n");
}

void	reverse_rotate_stack(t_stack *stack, char type)
{
	t_node	*tmp;

	if (stack == NULL)
		return ;
	if (type < 'A' || type > 'B')
		return ;
	tmp = stack->tail->prev;
	tmp->prev->next = stack->tail;
	stack->tail->prev = tmp->prev;
	stack->head->next->prev = tmp;
	tmp->next = stack->head->next;
	stack->head->next = tmp;
	tmp->prev = stack->head;
	stack->top = tmp;
	if (type == 'A')
		printf("rra\n");
	else if (type == 'B')
		printf("rrb\n");
}
