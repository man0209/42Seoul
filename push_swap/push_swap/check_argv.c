/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 22:52:06 by kokim             #+#    #+#             */
/*   Updated: 2022/04/29 01:12:17 by kokim            ###   ########.fr       */
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
	new_node->prev = stack->top->prev;
	new_node->next = stack->top;
	stack->top->prev->next = new_node;
	stack->top->prev = new_node;
	stack->top = new_node;
	stack->length++;
	// 첫번째 인자는 스택의 탑이 된다.
}

void	pop(t_stack *stack, t_node *remove)
{
	if (stack == NULL)
		return ;
	remove->prev->next = remove->next;
	remove->next->prev = remove->prev;
	
	free(remove);
}

static int is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' \
	|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int ft_atoi(char *str)
{
	int			minus;
	long long	result;

	minus = 1;
	result = 0;
	while (is_space(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			minus *= -1;
		if (*str == '+' || '-')
			return (0);
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
		if (result < INT_MIN || result > INT_MAX)
			return (0);
	}
	if (*str)
		return (0);
	return ((int)(result * minus));
}

void	check_argv(int ac, char **av, t_stack *a)
{
	// 중복된 숫자있으면 "Error\n" -> stack_a 에 넣고  따로 함수 만들어서
	// 정렬된 숫자 들어오면 exit(1);
	// "  " 들어와도 정렬되게
	int	index_av;
	int	num;

	index_av = 0;
	while (++index_av < ac)
	{
		num = ft_atoi(av[index_av]);
		if (num)
		{
			push(a, num);
		}
		else
		{
			printf("Error\n");
			remove_all(a->head);
			free_stack(a);
			return ;
		}
	}
}
/*
int main()
{
	t_stack *a;

	a = (t_stack *)malloc(sizeof(t_stack));
	init_stack(a);

	push(a, 3);

	push(a, 4);

	push(a, 5);

	t_node *cur = a->head;

	while (cur)
	{
		printf("%d\n", cur->data);
		printf("cur->prev : %p\n", cur->prev);
		printf("cur : %p\n", cur);
		printf("cur->next : %p\n", cur->next);

		cur = cur->next;
	}
}
*/
