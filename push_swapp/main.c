/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:48:16 by ekibar            #+#    #+#             */
/*   Updated: 2025/03/18 15:08:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->array = (int *)malloc(size * sizeof(int));
	stack->top = -1;
	return (stack);
}

int main(int argc, char **argv)
{
    int     i;
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);
    argv = argv_split(&argc, argv);
    if (!argv[1])
        ft_error();
    error_control(argc, argv);
    a = create_stack(argc - 1);
    b = create_stack(argc - 1);
    i = argc - 1;
    while (i > 0)
        push(a, ft_atoi(argv[i--]));
    push_swap(a, b);
    free_stack(a, b);
    free_argv(argv);
    return (0);
}
