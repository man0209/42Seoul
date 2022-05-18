/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kokim <kokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:32:44 by kokim             #+#    #+#             */
/*   Updated: 2022/05/18 10:19:45 by kokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

static int	is_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == '\f' || c == '\r'\
			|| c == ' ')
		return (1);
	return (0);
}

static int	ft_atoi(char *str, int *num)
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
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str++ - '0');
		if (result < INT_MIN || result > INT_MAX)
			return (1);
	}
	if (*str)
		return (1);
	*num = (int)(result * minus);
	return (0);
}

static int	split_str(char *str, t_stack *a)
{
	char	**split;
	int		i;
	int		num;

	split = ft_split(str, ' ');
	i = 0;
	while (split[i] != NULL)
		i++;
	if (i == 0)
		return (1);
	while (i--)
	{
		num = 0;
		if (ft_atoi(split[i], &num))
			return (1);
		push(a, num, 0);
		free(split[i]);
	}
	free(split);
	return (0);
}

void	check_str(char *str, t_stack *a, t_stack *b)
{
	int	num;

	num = 0;
	if (ft_strchr(str, ' '))
	{
		if (split_str(str, a))
		{
			ft_printf("Error\n");
			exit_on_error(a, b);
		}
		return ;
	}
	if (ft_atoi(str, &num))
	{
		ft_printf("Error\n");
		exit_on_error(a, b);
	}
	else
		push(a, num, 0);
}
