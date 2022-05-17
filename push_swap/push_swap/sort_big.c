/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:11:44 by kokim             #+#    #+#             */
/*   Updated: 2022/05/17 22:20:00 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_b_top(t_stack *b, int max_idx)
{
	t_node	*tmp;
	int		location;
	
	tmp = b->top;
	location = 0;
	while (tmp != b->tail)
	{
		if (tmp->index == max_idx)
		{
			if (location <= (b->length / 2))
			{
				while (b->head->next != tmp)
					rb(b, 0);
			}
			else
			{
				while (b->head->next != tmp)
					rrb(b, 0);
			}
			return ;
		}
		tmp = tmp->next;
		location++;
	}
}

static void	a_to_b(t_stack *a, t_stack *b)
{
	int	num;

	num = 0;
	while (a->length)
	{
		if (a->top->index <= num)
		{
			pb(b, a);
			num++;
		}
		else if (a->top->index > num && a->top->index <= num + a->chunk)
		{
			pb(b, a);
			rb(b, 0);
			num++;
		}
		else if (a->top->index > num + a->chunk)
		{
			ra(a, 0);
		}
	}
}

static void	b_to_a(t_stack *a, t_stack *b)
{
	int		max_idx;

	while(b->length)
	{
		max_idx = get_max_index(b);
		move_b_top(b, max_idx);
		pa(a, b);
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	
	a_to_b(a, b);
	b_to_a(a, b);
}


