/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:48:11 by ekibar            #+#    #+#             */
/*   Updated: 2025/03/18 14:01:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long    ft_numlen(char *str)
{
        int             i;
        long    result;
        int             k;

        i = 0;
        k = 0;
        result = 0;
        while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
                i++;
        if (str[i] == '-' || str[i] == '+')
        {
                i++;
        }
        while (str[i] >= '0' && str[i] <= '9')
        {
                result = result * 10 + str[i++] - '0';
                k++;
        }
        return (k);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_sorted(t_stack *a)
{
	int	i;

	i = a->top;
	while (i > 0)
	{
		if (a->array[i] > a->array[i - 1])
			return (0);
		i--;
	}
	return (1);
}

int	find_min_index(t_stack *stack)
{
	int	min_index;
	int	i;

	min_index = 0;
	i = 1;
	while (i <= stack->top)
	{
		if (stack->array[i] < stack->array[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

int	find_max_index(t_stack *stack)
{
	int	max_index;
	int	i;

	max_index = 0;
	i = 0;
	while (i <= stack->top)
	{
		if (stack->array[i] > stack->array[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}
