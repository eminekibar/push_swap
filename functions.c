#include "push_swap.h"

// Yığın A'nın sıralı olup olmadığını kontrol eder
int     is_sorted(t_stack *a)
{
    int     i;

    i = 0;
    while (i < a->top)
    {
        if (a->array[i] < a->array[i + 1])  // Eğer sıralı değilse
            return 0;  // Yığın sıralı değil
        i++;
    }
    return (1);  // Yığın sıralı
}

// Yığındaki en küçük elemanın indeksini bulur
int     find_min_index(t_stack *stack)
{
    int     min_index;
    int     i;

    min_index = 0;
    i = 1;
    while (i <= stack->top)
    {
        if (stack->array[i] < stack->array[min_index])  // Eğer daha küçükse
            min_index = i;  // Min indeksi güncelle
        i++;
    }
    return (min_index);  // En küçük elemanın indeksi
}

// Yığındaki en büyük elemanın indeksini bulur
int     find_max_index(t_stack *stack)
{
    int     max_index;
    int     i;

    max_index = 0;
    i = 0;
    while (i <= stack->top)
    {
        if (stack->array[i] > stack->array[max_index])  // Eğer daha büyükse
            max_index = i;  // Max indeksi güncelle
        i++;
    }
    return (max_index);  // En büyük elemanın indeksi
}



// B'deki uygun indeksin bulunması
int     find_target_index(t_stack *b, int value)
{
    int     i;
    int     best_index;

    best_index = -1;
    i = 0;
    while (i <= b->top)
    {
        if (b->array[i] < value && best_index == -1)
            best_index = i;
        else if (b->array[i] < value && b->array[best_index] < b->array[i])  
            best_index = i;
        i++;
    }
    if (best_index == -1) 
        best_index = find_max_index(b);
    return (best_index);
}

// B'ye taşınma maliyetini hesaplar
int     calculate_cost(t_stack *a, t_stack *b, int index)
{
    int     cost;
    int     b_target_index;  

    b_target_index = find_target_index(b, a->array[index]); 
    cost = 0;
    if (index <= a->top / 2)
        cost += index + 1;  
    else
        cost += (a->top - index);  
    if (b_target_index <= b->top / 2)
        cost += b_target_index + 1;  
    else
        cost += (b->top - b_target_index);
    return (cost);
}

// En düşük maliyetli elemanı bulur
int     find_cheapest_index(t_stack *a, t_stack *b)
{
    int     min_cost;
    int     cheapest_index;
    int     i;

    min_cost = 999999;
    cheapest_index = 0;
    i = 0;
    while (i <= a->top)
    {
        int cost = calculate_cost(a, b, i);  // Maliyeti hesapla
        if (cost < min_cost)
        {
            min_cost = cost;  // Eğer daha düşükse, güncelle
            cheapest_index = i;  // En ucuz elemanın indeksini sakla
        }
        i++;
    }
    return (cheapest_index);  // En ucuz elemanın indeksi
}
