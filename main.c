#include "push_swap.h"

// Stack oluşturma fonksiyonu
t_stack     *create_stack(int size)
{
    t_stack     *stack;

    stack = (t_stack *)malloc(sizeof(t_stack));       // Stack için bellek ayırma
    stack->array = (int *)malloc(size * sizeof(int)); // Yığın dizisi için bellek ayırma
    stack->top = -1;                                  // Yığının başlangıç durumu, yani boş
    return stack;
}

int     main(int argc, char **argv)
{
    int     i;
    t_stack     *a;
    t_stack     *b;

    if (argc < 2)
        return ((printf("Usage: %s <numbers>\n", argv[0])), 1);
    else if (argc == 2)
    {
        argc = 0;
        argv = ft_split(argv[1], ' ');
        while (argv[argc])
            argc++;
    }
    a = create_stack(argc - 1); // A yığını oluştur
    b = create_stack(argc - 1); // B yığını oluştur
    i = 1;
    while (i < argc)
        push(a, ft_atoi(argv[i++]));
    push_swap(a, b); // Push_swap fonksiyonunu çağır
    free(a->array);  // Yığınları serbest bırak
    free(b->array);
    free(a);
    free(b);
    return (0);
}