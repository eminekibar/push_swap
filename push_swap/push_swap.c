#include "push_swap.h"

void    rr_rrr(t_stack *a, t_stack *b, int *index_a, int *index_b)
{
    if (*index_a < a->top / 2 && *index_b < b->top / 2)
    {
        while ((a->top > *index_a && *index_a >= 0) && (b->top > *index_b && *index_b >= 0))
        {
            rrr(a, b);  
            (*index_a)--;
            (*index_b)--;
        }
    }
    else if (*index_a >= a->top / 2 && *index_b >= b->top / 2)
    {
        while ((a->top > *index_a && *index_a >= 0) && (b->top > *index_b && *index_b >= 0))
        {
            rr(a, b);  
            (*index_a)++;
            (*index_b)++;
        }
    }
}

void    end_rotation_a(t_stack *a, int *index_a)
{
    if (*index_a < 0)
        *index_a = a->top;
    else if (*index_a > a->top)
        *index_a = 0;
    while (a->top > *index_a && *index_a >= 0)  
    {
        if (*index_a < a->top / 2)
        {
            rra(a);  
            (*index_a)--;
        }
        else
        {  
            ra(a); 
            (*index_a)++;
        } 
    }
}

void    end_rotation_b(t_stack *b, int *index_b)
{
    if (*index_b < 0)
        *index_b = b->top;
    else if (*index_b > b->top)
        *index_b = 0;
    while (b->top > *index_b && *index_b >= 0)
    {
        if (*index_b < b->top / 2)
        {  
            rrb(b);  
            (*index_b)--;
        }
        else
        {
            rb(b);  
            (*index_b)++;
        }
    }
}

void    move_to_b(t_stack *a, t_stack *b)
{
    int     index_a;
    int     index_b;

    index_a = find_cheapest_index(a, b);
    index_b = find_target_index_b(b, a->array[index_a]);
    rr_rrr(a, b, &index_a, &index_b);
    end_rotation_a(a, &index_a);
    end_rotation_b(b, &index_b);
    pb(a, b);
}

void    move_to_a(t_stack *a, t_stack *b)
{
    int     index_a;
    index_a = find_target_index_a(a, b->array[b->top]);
    end_rotation_a(a, &index_a);
    pa(a, b);
}

void    sort_stacks(t_stack *a, t_stack *b)
{
    int     min_index;

    while (a->top > 2)
        move_to_b(a, b);
    sort_three(a);
    while (b->top >= 0)
        move_to_a(a, b);
    min_index = find_min_index(a);
    while (min_index != 0 && min_index >= 0 && min_index <= a->top)
    {
        if (min_index < a->top / 2)
        {
            rra(a);  
            min_index--;
        }
        else
        {
            ra(a);  
            min_index++;
        }
    }
}

void    sort_three(t_stack *a)
{
    if (a->array[0] > a->array[2] && a->array[2] > a->array[1])
        rra(a);
    else if (a->array[1] > a->array[0] && a->array[0] > a->array[2])
        ra(a);
    else if (a->array[1] > a->array[2] && a->array[2] > a->array[0])
        sa(a);
    else if (a->array[2] > a->array[0] && a->array[0] > a->array[1])
    {
        sa(a);
        ra(a);
    }
    else if (a->array[0] > a->array[1] && a->array[1] > a->array[2])
    {
        sa(a);
        rra(a);
    }
}

void    push_swap(t_stack *a, t_stack *b)
{
    if (!is_sorted(a))
    {
        if (a->top == 0)
            return;
        if (a->top == 1)
            sa(a);
        else if (a->top == 2)
            sort_three(a);
        else
        {
            if (a->top > 2)
                pb(a, b);
            if (a->top > 2)
                pb(a, b);
            sort_stacks(a, b);
        }
    }
}
