/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 22:05:45 by kokim             #+#    #+#             */
/*   Updated: 2022/05/18 10:24:10 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(t_stack *stack)
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

int	get_min_index(t_stack *stack)
{
	int		min;
	int		index;
	t_node	*top;

	top = stack->top;
	min = top->data;
	index = top->index;
	while (top != stack->tail)
	{
		if (top->data < min)
		{
			min = top->data;
			index = top->index;
		}
		top = top->next;
	}
	return (index);
}

int	get_max(t_stack *stack)
{
	int		max;
	t_node	*tmp;

	tmp = stack->top;
	max = 0;
	while (tmp != stack->tail)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	return (max);
}

int	get_min(t_stack *stack)
{
	int		min;
	t_node	*tmp;

	tmp = stack->top;
	min = tmp->data;
	while (tmp != stack->tail)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	return (min);
}
