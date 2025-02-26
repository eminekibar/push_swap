#include "push_swap.h"

// Yığın üzerinde rotate işlemi (her elemanı bir sağa kaydırma)
void rotate(t_stack *stack)
{
    if (stack->top < 1) return;  // Eğer yığın tek elemanlıysa, işlem yapma
    int temp = stack->array[stack->top];  // Geçici değişken oluştur
    for (int i = stack->top; i > 0; i--)  // Yığındaki her elemanı bir sağa kaydır
    {
        stack->array[i] = stack->array[i - 1];
    }
    stack->array[0] = temp;  // Son elemanı en başa taşı
}

// Stack üzerinde ra işlemi (rotate)
void ra(t_stack *a)
{
    rotate(a);  // Rotate işlemi uygula
    printf("ra\n");  // Yığını göster
}

// Stack üzerinde rb işlemi (rotate)
void rb(t_stack *b)
{
    rotate(b);  // Rotate işlemi uygula
    printf("rb\n");  // Yığını göster
}

// Stack üzerinde rr işlemi (her iki yığın için rotate)
void rr(t_stack *a, t_stack *b)
{
    rotate(a);  // Yığın A üzerinde rotate
    rotate(b);  // Yığın B üzerinde rotate
    printf("rr\n");  // Yığınları göster
}