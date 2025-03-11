#include "push_swap.h"

void    push(t_stack *stack, int value)
{
    stack->array[++stack->top] = value;
}

int     pop(t_stack *stack)
{
    return stack->array[stack->top--];
}

void    pa(t_stack *a, t_stack *b)
{
    if (b->top < 0)
        return ;
    push(a, pop(b));
    write(1,"pa\n",3);
}

void    pb(t_stack *a, t_stack *b)
{
    if (a->top < 0)
        return ;
    push(b, pop(a));
    write(1,"pb\n",3);
}
