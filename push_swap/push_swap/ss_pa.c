/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:55:24 by kokim             #+#    #+#             */
/*   Updated: 2022/05/18 10:25:48 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack, int flag)
{
	int		tmp_data;
	int		tmp_index;

	if (stack->length < 2)
		return ;
	tmp_data = stack->top->data;
	tmp_index = stack->top->index;
	stack->top->data = stack->top->next->data;
	stack->top->index = stack->top->next->index;
	stack->top->next->data = tmp_data;
	stack->top->next->index = tmp_index;
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int flag)
{
	int	tmp_data;
	int	tmp_index;

	if (stack->length < 2)
		return ;
	tmp_data = stack->top->data;
	tmp_index = stack->top->index;
	stack->top->data = stack->top->next->data;
	stack->top->index = stack->top->next->index;
	stack->top->next->data = tmp_data;
	stack->top->next->index = tmp_index;
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	if (a->length < 2)
		return ;
	if (b->length < 2)
		return ;
	sa(a, 1);
	sb(b, 1);
	write(1, "ss\n", 3);
}

void	pa(t_stack *in, t_stack *out)
{
	int	data;
	int	index;

	if (out->head->next == out->tail)
		return ;
	data = out->top->data;
	index = out->top->index;
	push(in, data, index);
	pop(out);
	write(1, "pa\n", 3);
}

void	pb(t_stack *in, t_stack *out)
{
	int	data;
	int	index;

	if (out->head->next == out->tail)
		return ;
	data = out->top->data;
	index = out->top->index;
	push(in, data, index);
	pop(out);
	write(1, "pb\n", 3);
}
