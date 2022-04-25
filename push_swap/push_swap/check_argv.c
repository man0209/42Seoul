/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:52:06 by kokim             #+#    #+#             */
/*   Updated: 2022/04/25 00:44:39 by kokim            ###   ########.fr       */
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
	new_node->prev = stack->tail;
	new_node->next = NULL;
	// 첫번째 인자는 스택의 탑이 된다.
}

void	check_argv(int ac, char **av, t_stack *a)
{
	
	
	// 숫자 아니면 "Error\n"
	// 중복된 숫자있으면 "Error\n"
	// MAXINT 넘으면 "Error\n"
	// 정렬된 숫자 들어오면 exit(1);
	// "  " 들어와도 정렬되게
}