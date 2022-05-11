/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:52:06 by kokim             #+#    #+#             */
/*   Updated: 2022/05/11 22:28:40 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int num, int flag, int index)
{
	t_node	*new_node;

	new_node = (t_node*)malloc(sizeof(t_node *));
	if (new_node == NULL)
		return ;
	new_node->data = num;
	if (flag == 0)
		new_node->index = stack->tmp_index++;
	if (flag == 1)
		new_node->index = index;
	new_node->prev = stack->top->prev;
	new_node->next = stack->top;
	stack->top->prev->next = new_node;
	stack->top->prev = new_node;
	stack->top = new_node;
	stack->length++;
	// 첫번째 인자는 스택의 탑이 된다.
}

void	pop(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	stack->head->next = tmp->next;
	tmp->next->prev = stack->head;
	stack->top = stack->head->next;;
	free_node(tmp);
	stack->length--;
}

int	check_sorted(t_stack *a)
{
	t_node *tmp;
	
	tmp = a->top;
	if (tmp->next == a->tail)
	{
		return (0);
	}
	while (tmp != a->tail->prev)
	{
		if (tmp->data >= tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int	check_duplicated(t_stack *a)
{
	t_node	*tmp;

	tmp = a->top;
	if (tmp->next == a->tail)
	{
		return (0);
	}
	while (tmp != a->tail->prev)
	{
		if (tmp->data == a->tail->prev->data)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
void	check_argv(int ac, char **av, t_stack *a, t_stack *b)
{	
	int	index_av;

	index_av = ac;
	while (--index_av)
		check_str(av[index_av], a, b);
	if (check_sorted(a))
	{
		exit_on_error(a, b);
	}
	if (check_duplicated(a))
	{
		printf("2Error\n");
		exit_on_error(a, b);
	}
}