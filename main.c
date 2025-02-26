#include "push_swap.h"

// Stack oluşturma fonksiyonu
t_stack *create_stack(int size)
{
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));  // Stack için bellek ayırma
    stack->array = (int *)malloc(size * sizeof(int));     // Yığın dizisi için bellek ayırma
    stack->top = -1;  // Yığının başlangıç durumu, yani boş
    return stack;
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Kullanım: %s <sayılar>\n", argv[0]);
        return 1;
    }

    t_stack *a = create_stack(argc - 1);  // A yığını oluştur
    t_stack *b = create_stack(argc - 1);  // B yığını oluştur

    for (int i = 1; i < argc; i++) {
        push(a, atoi(argv[i]));
    }

    push_swap(a, b);  // Push_swap fonksiyonunu çağır

    // Yığınları serbest bırak
    free(a->array);
    free(b->array);
    free(a);
    free(b);

    return 0;
}