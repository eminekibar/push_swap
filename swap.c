#include "push_swap.h"

// Swap işlemi: Yığının üstteki iki elemanını takas yapma
void swap(t_stack *stack)
{
    if (stack->top < 1) return;  // Yığın tek elemanlıysa işlem yapma
    int temp = stack->array[stack->top];  // Geçici değişken oluştur
    stack->array[stack->top] = stack->array[stack->top - 1];  // Yığındaki üstteki iki elemanı takas et
    stack->array[stack->top - 1] = temp;
}

// Stack üzerinde sa işlemi (swap)
void sa(t_stack *a)
{
    swap(a);  // Swap işlemi uygula
    printf("sa\n");  // Yığını göster
}

// Stack üzerinde sb işlemi (swap)
void sb(t_stack *b)
{
    swap(b);  // Swap işlemi uygula
    printf("sb\n");  // Yığını göster
}

// Stack üzerinde ss işlemi (her iki yığın için swap)
void ss(t_stack *a, t_stack *b)
{
    swap(a);  // Yığın A üzerinde swap
    swap(b);  // Yığın B üzerinde swap
    printf("ss\n");  // Yığınları göster
}