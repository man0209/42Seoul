/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:39:56 by kokim             #+#    #+#             */
/*   Updated: 2022/04/29 01:13:52 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
2. 스택 a, b 링크드 리스트로 구현.
3. 과제에서 요구한 11가지 링크드 리스트로 출력까지 구현.
4. 아직 모름
*/

void	init_stack(t_stack *stack)
{
	t_node	*head;
	t_node	*tail;
	
	head = (t_node *)malloc(sizeof(t_node));
	if (head == NULL)
		return ;
	tail = (t_node *)malloc(sizeof(t_node));
	if (tail == NULL)
		return ;
	head->data = 0;
	head->prev = NULL;
	head->next = tail;
	tail->data = 0;
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

	if (ac < 3)
		return (0);
	stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (stack_a == NULL)
		exit (1);
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (stack_b == NULL)
		exit (1);
	init_stack(stack_a);
	init_stack(stack_b);
	check_argv(ac, av, stack_a);
	t_node *cur = stack_a->head;
	while (cur)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
	remove_all(stack_b->head);
	free_stack(stack_b);
}
