/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:39:56 by kokim             #+#    #+#             */
/*   Updated: 2022/05/03 20:26:39 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
3. 과제에서 요구한 11가지 링크드 리스트로 출력까지 구현.
4. 아직 모름
*/
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
	stack->size = 0;
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
	remove_all(stack_a);
	remove_all(stack_b);
}
