#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>

typedef struct s_stack
{
    int *array;
    int top;
}   t_stack;

long    ft_atoi(const char *str);
int  count_words(char *str, char separator);
char     *get_next_word(char *str, char separator);
char    **ft_split(char *str, char separator);
t_stack     *create_stack(int size);
int     is_sorted(t_stack *a);
int     find_min_index(t_stack *stack);
int     find_max_index(t_stack *stack);
void    sort_three(t_stack *a);
int     find_target_index_b(t_stack *b, int value);
int     find_target_index_a(t_stack *a, int value);
int     calculate_cost(t_stack *a, t_stack *b, int index);
int     find_cheapest_index(t_stack *a, t_stack *b);
void    rr_rrr(t_stack *a, t_stack *b, int *index_a, int *index_b);
void    end_rotation_a(t_stack *a, int *index_a);
void    end_rotation_b(t_stack *b, int *index_b);
void    move_to_b(t_stack *a, t_stack *b);
void    sort_stacks(t_stack *a, t_stack *b);
void    push_swap(t_stack *a, t_stack *b);
void    push(t_stack *stack, int value);
int     pop(t_stack *stack);
void    swap(t_stack *stack);
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void    rotate(t_stack *stack);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rev_rotate(t_stack *stack);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

#endif