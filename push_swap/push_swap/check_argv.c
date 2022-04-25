/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:52:06 by kokim             #+#    #+#             */
/*   Updated: 2022/04/25 16:26:28 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	push(t_stack *stack, int num)
{
	t_node	*new_node;

	new_node = (t_node*)malloc(sizeof(t_node *));
	if (new_node == NULL)
		return ;
	new_node->data = num;
	stack->top->next = new_node;
	stack->tail->prev = new_node;
	new_node->prev = stack->top;:
	new_node->next = stack->tail;
	stack->top = stack->head->next;
	stack->length++;
	// 첫번째 인자는 스택의 탑이 된다.
}

/*
void	check_argv(int ac, char **av, t_stack *a)
{
	t_stack *a;

	a = (t_stack *)malloc(sizeof(t_stack)
	
	// 숫자 아니면 "Error\n"
	// 중복된 숫자있으면 "Error\n"
	// MAXINT 넘으면 "Error\n"
	// 정렬된 숫자 들어오면 exit(1);
	// "  " 들어와도 정렬되게
}
*/
int main()
{
	t_stack *a;

	a = (t_stack *)malloc(sizeof(t_stack));
	init_stack(a);

	push(a, 3);
	printf("length : %d\n", a->length);
	printf("stack->top->next : %p\n", a->top->next);
	push(a, 4);
	printf("length : %d\n", a->length);
	printf("stack->top->next : %p\n", a->top->next);
	push(a, 5);
	printf("length : %d\n", a->length);
	printf("stack->top->next : %p\n", a->top->next);
	t_node *cur = a->tail;
	printf("stack->tail : %p\n", a->tail);
	printf("stack->top : %p\n", a->top);

	while (cur)
	{
		printf("%d\n", cur->data);
		printf("cur->prev : %p\n", cur->prev);
		printf("cur : %p\n", cur);
		printf("cur->next : %p\n", cur->next);

		cur = cur->prev;
	}
}

