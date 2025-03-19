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

char    *ft_strjoin_args(int argc, char **argv)
{
    int     i;
    int     len;
    char    *joined;
    int     pos;
	int		j;

    len = 0;
	i = 1;
    while (i < argc)
        len += ft_strlen(argv[i++]) + 1;
    joined = (char *)malloc(sizeof(char) * len);
    if (!joined)
        return (NULL);
    pos = 0;
	i = 1;
    while (i < argc)
    {
		j = 0;
		while (argv[i][j])
		{
			joined[pos++] = argv[i][j++];
		}
        if (i < argc - 1)
            joined[pos++] = ' ';
		i++;
    }
    joined[pos] = '\0';
    return (joined);
}

char    **argv_split(int *argc, char **argv)
{
    char *joined_args;

    joined_args = ft_strjoin_args(*argc, argv);
    if (!joined_args)
		return (NULL);
	argv = ft_split(joined_args, ' ');
    free(joined_args);
	*argc = 0;
    while (argv[*argc])
        *argc += 1;
    return (argv);
}

int main(int argc, char **argv)
{
    int     i;
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);
    argv = argv_split(&argc, argv);
    if (!argv)
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
