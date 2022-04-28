/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_uti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:25:53 by kokim             #+#    #+#             */
/*   Updated: 2022/04/29 01:02:08 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_node *node)
{
	free(node);
	node == NULL;
}

void	free_stack(t_stack *stack)
{
	free(stack);
	stack == NULL;
}

void	remove_all(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (head)
	{
		free_node(head);
		tmp = tmp->next;
		head = tmp;
	}
}