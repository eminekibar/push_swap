#include "push_swap.h"

void    rev_rotate(t_stack *stack)
{
    int     temp;
    int     i;

    if (stack->top < 1)
        return ;
    temp = stack->array[0];
    i = 0;
    while (i < stack->top)
    {
        stack->array[i] = stack->array[i + 1];
        i++;
    }
    stack->array[stack->top] = temp;
}

void    rra(t_stack *a)
{
    rev_rotate(a);
    write(1,"rra\n",4);
}

void    rrb(t_stack *b)
{
    rev_rotate(b);
    write(1,"rrb\n",4);
}

void    rrr(t_stack *a, t_stack *b)
{
    rev_rotate(a);
    rev_rotate(b);
    write(1,"rrr\n",4);
}
