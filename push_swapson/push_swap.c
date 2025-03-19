/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekibar <ekibar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:48:28 by ekibar            #+#    #+#             */
/*   Updated: 2025/03/13 15:46:35 by ekibar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stacks(t_stack *a, t_stack *b)
{
	int	max_index;

	while (a->top > 2)
		move_to_b(a, b);
	sort_three(a);
	while (b->top >= 0)
		move_to_a(a, b);
	max_index = find_max_index(a);
	while (max_index != 0 && max_index >= 0 && max_index <= a->top)
	{
		if (max_index < a->top / 2)
		{
			rra(a);
			max_index--;
		}
		else
		{
			ra(a);
			max_index++;
		}
	}
}

void	sort_three(t_stack *a)
{
	if (a->array[0] < a->array[1] && a->array[1] < a->array[2])
	{
		ra(a);
		sa(a);
	}
	else if (a->array[0] < a->array[2] && a->array[2] < a->array[1])
		rra(a);
	else if (a->array[1] < a->array[0] && a->array[0] < a->array[2])
		ra(a);
	else if (a->array[1] < a->array[2] && a->array[2] < a->array[0])
		sa(a);
	else if (a->array[2] < a->array[0] && a->array[0] < a->array[1])
	{
		sa(a);
		ra(a);
	}
}

void	push_swap(t_stack *a, t_stack *b)
{
	if (!is_sorted(a))
	{
		if (a->top == 0)
			return ;
		else if (a->top == 1)
			ra(a);
		else
		{
			if (a->top > 2)
				pb(a, b);
			if (a->top > 2)
				pb(a, b);
			sort_stacks(a, b);
		}
	}
}
