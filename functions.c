#include "push_swap.h"

int     is_sorted(t_stack *a)
{
    int     i;

    i = a->top;
    while (i > 0)
    {
        if (a->array[i] > a->array[i - 1])
            return 0;
        i--;
    }
    return (1);
}

int     find_min_index(t_stack *stack)
{
    int     min_index;
    int     i;

    min_index = 0;
    i = 1;
    while (i <= stack->top)
    {
        if (stack->array[i] < stack->array[min_index])
            min_index = i;
        i++;
    }
    return (min_index);
}

int     find_max_index(t_stack *stack)
{
    int     max_index;
    int     i;

    max_index = 0;
    i = 0;
    while (i <= stack->top)
    {
        if (stack->array[i] > stack->array[max_index])
            max_index = i;
        i++;
    }
    return (max_index);
}

int     find_target_index_a(t_stack *a, int value)
{
    int     i;
    int     best_index;

    best_index = -1;
    i = a->top;
    while (i >= 0)
    {
        if (a->array[i] > value && best_index == -1)
            best_index = i;
        else if (a->array[i] > value && a->array[best_index] > a->array[i])  
            best_index = i;
        i--;
    }
    if (best_index == -1) 
        best_index = find_min_index(a);
    return (best_index);
}

int     find_target_index_b(t_stack *b, int value) //kendisinden küçük en büyük yoksa max
{
    int     i;
    int     best_index;

    best_index = -1;
    i = b->top;
    while (i >= 0)
    {
        if (b->array[i] < value && best_index == -1)
            best_index = i;
        else if (b->array[i] < value && b->array[best_index] < b->array[i])  
            best_index = i;
        i--;
    }
    if (best_index == -1) 
        best_index = find_max_index(b);
    return (best_index);
}

int     calculate_cost(t_stack *a, t_stack *b, int index)
{
    int     cost;
    int     b_target_index;  

    b_target_index = find_target_index_b(b, a->array[index]); 
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

int     find_cheapest_index(t_stack *a, t_stack *b)
{
    int     min_cost;
    int     cheapest_index;
    int     i;

    min_cost = 999999;
    cheapest_index = 0;
    i = a->top;
    while (i >= 0)
    {
        int cost = calculate_cost(a, b, i);
        if (cost < min_cost)
        {
            min_cost = cost;
            cheapest_index = i;
        }
        i--;
    }
    return (cheapest_index);
}
