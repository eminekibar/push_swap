#include "push_swap.h"

t_stack     *create_stack(int size)
{
    t_stack     *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    stack->array = (int *)malloc(size * sizeof(int));
    stack->top = -1;
    return stack;
}

void    free_stack(t_stack *a, t_stack *b)
{
    free(a->array);
    free(b->array);
    free(a);
    free(b);
}

void    free_argv(char **argv)
{
    int     i;

    i = 0;
    while(argv[i++])
        free(argv[i]);
    free(argv);
}

int ft_is_numeric(char **argv)
{
    int     i;
    int     j;

    i = 1;
    while (argv[i])
    {
        j = 0;
        if (!argv[i] || argv[i][0] == '\0') // Boş string kontrolü
            return (0);
        if (argv[i][0] == '-' || argv[i][0] == '+') // İlk karakter '-' veya '+' olabilir
            j++;
        while (argv[i][j]) // Stringin geri kalanını kontrol et
        {
            if (argv[i][j] < '0' || argv[i][j] > '9') // Rakam değilse
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int is_duplicate(char **argv, int argc)
{
    int i, j;

    for (i = 1; i < argc; i++)
    {
        for (j = i + 1; j < argc; j++)
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j])) // Aynı sayı varsa
                return (1);
        }
    }
    return (0);
}

int is_valid_int(char **argv)
{
    int i = 1;
    long nbr;

    while (argv[i])
    {
        nbr = ft_atoi(argv[i]);
        if(nbr > INT_MAX || nbr < INT_MIN)
            free_argv(argv);
        i++;
    }
    return (1); // Geçerli sayı
}

void    error_control(int argc, char **argv)
{
    if (!ft_is_numeric(argv))
    {
        write(1, "Error:\n", 5);
        free_argv(argv);
        exit (1);
    }
    if (!is_valid_int(argv))
    {
        write(2, "Error:\n", 5);
        free_argv(argv);
        exit(1);
    }
    if (is_duplicate(argv, argc))
    {
        write(2, "Error:\n", 5);
        free_argv(argv);
        exit(1);
    }
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
    free_argv(argv);
    return (0);
}