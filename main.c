#include "push_swap.h"

t_stack     *create_stack(int size)
{
    t_stack     *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    stack->array = (int *)malloc(size * sizeof(int));
    stack->top = -1;
    return stack;
}

int     main(int argc, char **argv)
{
    int     i;
    t_stack     *a;
    t_stack     *b;

    i = 1;
    if (argc < 2)
        exit (1);
    else if (argc == 2)
    {
        argc = 0;
        argv = ft_split(argv[1], ' ');
        while (argv[argc])
            argc++;
    }
    error_control(argc, argv);
    a = create_stack(argc - 1);
    b = create_stack(argc - 1);
    i = 1;
    while (i < argc)
        push(a, ft_atoi(argv[i++]));
    push_swap(a, b);
    free_stack(a, b);
    return (0);
}