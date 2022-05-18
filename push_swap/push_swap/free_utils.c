/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:25:53 by kokim             #+#    #+#             */
/*   Updated: 2022/05/18 10:27:47 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_node(t_node *node)
{
	free(node);
	node = NULL;
}

void	free_stack(t_stack *stack)
{
	free(stack);
	stack = NULL;
}

void	remove_all(t_stack *stack)
{	
	t_node	*cur;
	t_node	*next;

	cur = stack->head->next;
	while (cur != stack->tail)
	{
		next = cur->next;
		free_node(cur);
		cur = next;
	}
	free_node(stack->head);
	free_node(stack->tail);
	free_stack(stack);
}

void	exit_on_error(t_stack *a, t_stack *b)
{
	remove_all(a);
	remove_all(b);
	exit (1);
}

void	show(t_stack *stack, char name)
{
	t_node	*cur;
	char	a;

	a = name;
	ft_printf("-----------------------\n");
	ft_printf("%c%c%c%c%c%c\n", a, a, a, a, a, a);
	cur = stack->head->next;
	while (cur != stack->tail)
	{
		ft_printf("%d\n", cur->data);
		ft_printf("index : %d\n", cur->index);
		cur = cur->next;
	}
	ft_printf("-----------------------\n");
}
