/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:39:56 by kokim             #+#    #+#             */
/*   Updated: 2022/05/17 22:02:52 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	make_chunk(t_stack *stack)
{
	int	length;
	
	length = stack->length;
	if (length <= 10)
		stack->chunk = 1;
	else if (length <= 20)
		stack->chunk = 2;
	else if (length <= 50)
		stack->chunk = 4;
	else if (length < 100)
		stack->chunk = 8;
	else
		stack->chunk = 0.000000053 * (length * length) + 0.03 * length + 14.5;
}

static void	init_stack(t_stack *stack)
{
	t_node	*head;
	t_node	*tail;
	
	head = (t_node *)malloc(sizeof(t_node));
	if (head == NULL)
		return ;
	tail = (t_node *)malloc(sizeof(t_node));
	if (tail == NULL)
		return ;
	head->prev = NULL;
	head->next = tail;
	head->data = 0;
	head->index = 0;
	tail->prev = head;
	tail->next = NULL;
	tail->data = 0;
	tail->index = 0;
	stack->head = head;
	stack->tail = tail;
	stack->length = 0;
	stack->chunk = 0;
	stack->top = tail;
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (stack_a == NULL)
		return (0);
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (stack_b == NULL)
		return (0);
	init_stack(stack_a);
	init_stack(stack_b);
	check_argv(ac, av, stack_a, stack_b);
	make_chunk(stack_a);
	if (stack_a->length > 5)
		sort_big(stack_a, stack_b);
	else
		sort_upto_five(stack_a, stack_b);
	show(stack_a, 'A');
	show(stack_b, 'B');
	remove_all(stack_a);
	remove_all(stack_b);
	return (0);
}
