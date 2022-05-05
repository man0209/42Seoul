/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_upto_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 21:46:03 by kokim             #+#    #+#             */
/*   Updated: 2022/05/05 23:29:55 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->top;
	if (tmp->data > tmp->next->data)
		swap_stack(stack, 'A');
}

// static void	sort_three(t_stack *stack)
// {
// 	if (check_sorted(stack))
// 		return ;
	
// }

void	sort_upto_five(t_stack *a)
{
	if (a->length == 2)
		sort_two(a);
}