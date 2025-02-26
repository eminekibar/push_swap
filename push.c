#include "push_swap.h"

// Stack'e eleman ekleme fonksiyonu
void    push(t_stack *stack, int value)
{
    stack->array[++stack->top] = value;  // Yeni elemanı yığının en üstüne ekle
}

// Stack'ten eleman çıkarma fonksiyonu
int     pop(t_stack *stack)
{
    return stack->array[stack->top--];  // Yığının en üst elemanını çıkar ve geri döndür
}

// Stack'e eleman taşıma (A -> B)
void    pa(t_stack *a, t_stack *b)
{
    if (b->top < 0)
        return;  // Eğer B yığını boşsa, işlem yapma
    push(a, pop(b));  // B'deki elemanı A'ya taşı
    printf("pa\n");  // Yığını göster
}

// Stack'e eleman taşıma (B -> A)
void    pb(t_stack *a, t_stack *b)
{
    if (a->top < 0)
        return;  // Eğer A yığını boşsa, işlem yapma
    push(b, pop(a));  // A'daki elemanı B'ye taşı
    printf("pb\n");  // Yığını göster
}
