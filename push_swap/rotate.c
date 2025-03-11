#include "push_swap.h"

void    rotate(t_stack *stack)
{
    int     temp;
    int     i;

    if (stack->top < 1)
        return ;
    temp = stack->array[stack->top];
    i = stack->top;
    while (i > 0)
    {
        stack->array[i] = stack->array[i - 1];
        i--;
    }
    stack->array[0] = temp;
}

void    ra(t_stack *a)
{
    rotate(a);
    write(1,"ra\n",3);
}

void    rb(t_stack *b)
{
    rotate(b);
    write(1,"rb\n",3);
}

void    rr(t_stack *a, t_stack *b)
{
    rotate(a);
    rotate(b);
    write(1,"rr\n",3);
}
