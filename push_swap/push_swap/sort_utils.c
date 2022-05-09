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

	max = 0;
	index = 0;
	top = stack->top;
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
	t_node	*top;

	top = stack->top;
	min = top->data;
	while (top->next != stack->tail)
	{
		if (min < top->data)
			min = top->data;
		top = top->next;
	}
	return (min);
}