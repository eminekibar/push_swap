#include "push_swap.h"

// Yığın üzerinde reverse rotate işlemi (her elemanı bir sola kaydırma)
void rev_rotate(t_stack *stack)
{
    if (stack->top < 1) return;  // Eğer yığın tek elemanlıysa, işlem yapma
    int temp = stack->array[0];  // Geçici değişken oluştur
    for (int i = 0; i < stack->top; i++)  // Yığındaki her elemanı bir sola kaydır
    {
        stack->array[i] = stack->array[i + 1];
    }
    stack->array[stack->top] = temp;  // İlk elemanı sona taşı
}

// Stack üzerinde rra işlemi (reverse rotate)
void rra(t_stack *a)
{
    rev_rotate(a);  // Reverse rotate işlemi uygula
    printf("rra\n");  // Yığını göster
}

// Stack üzerinde rrb işlemi (reverse rotate)
void rrb(t_stack *b)
{
    rev_rotate(b);  // Reverse rotate işlemi uygula
    printf("rrb\n");  // Yığını göster
}

// Stack üzerinde rrr işlemi (her iki yığın için reverse rotate)
void rrr(t_stack *a, t_stack *b)
{
    rev_rotate(a);  // Yığın A üzerinde reverse rotate
    rev_rotate(b);  // Yığın B üzerinde reverse rotate
    printf("rrr\n");  // Yığınları göster
}