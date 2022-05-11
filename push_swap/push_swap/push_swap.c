/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:39:56 by kokim             #+#    #+#             */
/*   Updated: 2022/05/11 22:41:31 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	tail->prev = head;
	tail->next = NULL;
	stack->head = head;
	stack->tail = tail;
	stack->length = 0;
	stack->tmp_index = 0;
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
	show(stack_a, 'A');
	if (stack_a->length > 5)
		sort_a_b(stack_a, stack_b);
	else
		sort_upto_five(stack_a, stack_b);
	show(stack_a, 'A');
	show(stack_b, 'B');

	printf("stack_a->length : %d\n", stack_a->length);
	printf("Max : %d\n", get_max(stack_a));
	printf("Min : %d\n", get_min(stack_a));
	remove_all(stack_a);
	remove_all(stack_b);
	return (0);
}
