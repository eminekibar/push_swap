#include "push_swap.h"

void    swap(t_stack *stack)
{
    int     temp;

    if (stack->top < 1) 
        return ;
    temp = stack->array[stack->top];
    stack->array[stack->top] = stack->array[stack->top - 1];
    stack->array[stack->top - 1] = temp;
}

void    sa(t_stack *a)
{
    swap(a);
    write(1,"sa\n",3);
}

void    sb(t_stack *b)
{
    swap(b);
    write(1,"sb\n",3);
}

void    ss(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
    write(1,"ss\n",3);
}
