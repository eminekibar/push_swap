/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekibar <ekibar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:46:42 by ekibar            #+#    #+#             */
/*   Updated: 2025/03/13 15:52:17 by ekibar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_rrr(t_stack *a, t_stack *b, int *index_a, int *index_b)
{
	if (*index_a < a->top / 2 && *index_b < b->top / 2)
	{
		while ((a->top > *index_a && *index_a >= 0) && (b->top > *index_b
				&& *index_b >= 0))
		{
			rrr(a, b);
			(*index_a)--;
			(*index_b)--;
		}
	}
	else if (*index_a >= a->top / 2 && *index_b >= b->top / 2)
	{
		while ((a->top > *index_a && *index_a >= 0) && (b->top > *index_b
				&& *index_b >= 0))
		{
			rr(a, b);
			(*index_a)++;
			(*index_b)++;
		}
	}
}

void	end_rotation_a(t_stack *a, int *index_a)
{
	if (*index_a < 0)
		*index_a = a->top;
	else if (*index_a > a->top)
		*index_a = 0;
	while (a->top > *index_a && *index_a >= 0)
	{
		if (*index_a < a->top / 2)
		{
			rra(a);
			(*index_a)--;
		}
		else
		{
			ra(a);
			(*index_a)++;
		}
	}
}

void	end_rotation_b(t_stack *b, int *index_b)
{
	if (*index_b < 0)
		*index_b = b->top;
	else if (*index_b > b->top)
		*index_b = 0;
	while (b->top > *index_b && *index_b >= 0)
	{
		if (*index_b < b->top / 2)
		{
			rrb(b);
			(*index_b)--;
		}
		else
		{
			rb(b);
			(*index_b)++;
		}
	}
}

void	move_to_b(t_stack *a, t_stack *b)
{
	int	index_a;
	int	index_b;

	index_a = find_cheapest_index(a, b);
	index_b = find_target_index_b(b, a->array[index_a]);
	rr_rrr(a, b, &index_a, &index_b);
	end_rotation_a(a, &index_a);
	end_rotation_b(b, &index_b);
	pb(a, b);
}

void	move_to_a(t_stack *a, t_stack *b)
{
	int	index_a;

	index_a = find_target_index_a(a, b->array[b->top]);
	end_rotation_a(a, &index_a);
	pa(a, b);
}
