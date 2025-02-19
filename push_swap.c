#include <stdio.h>
#include <stdlib.h>

// Stack yapısı
typedef struct s_stack
{
    int *array;
    int top;
} t_stack;

void display(t_stack *a)
{
    printf("Sorted Stack: ");
    for (int i = 0; i <= a->top; i++)
    {
        printf("%d ", a->array[i]);
    }
    printf("\n");
}

// Stack oluşturma
t_stack *create_stack(int size)
{
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    stack->array = (int *)malloc(size * sizeof(int));
    stack->top = -1;
    return stack;
}

// Stack'e eleman ekleme
void push(t_stack *stack, int value)
{
    stack->array[++stack->top] = value;
}

// Stack'ten eleman çıkarma
int pop(t_stack *stack)
{
    return stack->array[stack->top--];
}

// Swap işlemi
void swap(t_stack *stack)
{
    if (stack->top < 1) return;
    int temp = stack->array[stack->top];
    stack->array[stack->top] = stack->array[stack->top - 1];
    stack->array[stack->top - 1] = temp;
}

void sa(t_stack *a)
{
    swap(a);
    printf("sa\n");
}

void sb(t_stack *b)
{
    swap(b);
    printf("sb\n");
}

void ss(t_stack *a, t_stack *b)
{
    swap(a);
    swap(b);
    printf("ss\n");
}

// Push işlemi
void pa(t_stack *a, t_stack *b)
{
    if (b->top < 0) return;
    push(a, pop(b));
    printf("pa\n");
}

void pb(t_stack *a, t_stack *b)
{
    if (a->top < 0) return;
    push(b, pop(a));
    printf("pb\n");
}

// Rotate işlemi
void rotate(t_stack *stack)
{
    if (stack->top < 1) return;
    int temp = stack->array[stack->top];
    for (int i = stack->top; i > 0; i--)
    {
        stack->array[i] = stack->array[i - 1];
    }
    stack->array[0] = temp;
}

void ra(t_stack *a)
{
    rotate(a);
    printf("ra\n");
}

void rb(t_stack *b)
{
    rotate(b);
    printf("rb\n");
}

void rr(t_stack *a, t_stack *b)
{
    rotate(a);
    rotate(b);
    printf("rr\n");
}

// Reverse rotate işlemi
void rev_rotate(t_stack *stack)
{
    if (stack->top < 1) return;
    int temp = stack->array[0];
    for (int i = 0; i < stack->top; i++)
    {
        stack->array[i] = stack->array[i + 1];
    }
    stack->array[stack->top] = temp;
}

void rra(t_stack *a)
{
    rev_rotate(a);
    printf("rra\n");
}

void rrb(t_stack *b)
{
    rev_rotate(b);
    printf("rrb\n");
}

void rrr(t_stack *a, t_stack *b)
{
    rev_rotate(a);
    rev_rotate(b);
    printf("rrr\n");
}

int is_sorted(t_stack *a)
{
    for (int i = 0; i < a->top; i++)
    {
        if (a->array[i] > a->array[i + 1])
            return 0;
    }
    return 1;
}

// Helper functions to find min and max
int find_min_index(t_stack *stack)
{
    int min_index = 0;
    for (int i = 1; i <= stack->top; i++)
    {
        if (stack->array[i] < stack->array[min_index])
            min_index = i;
    }

    return min_index;
}

int find_max_index(t_stack *stack)
{
    int max_index = 0;
    for (int i = 0; i <= stack->top; i++)
    {
        if (stack->array[i] > stack->array[max_index])
            max_index = i;
    }
    return max_index;
}

// Sorting functions
void sort_three(t_stack *a) {
    if (a->array[0] > a->array[2] && a->array[2] > a->array[1])
    {
        // A C B -> sa
        sa(a);
    } 
    else if (a->array[1] > a->array[0] && a->array[0] > a->array[2])
    {
        // B A C -> sa, ra
        sa(a);
        ra(a);
    } 
    else if (a->array[1] > a->array[2] && a->array[2] > a->array[0])
    {
        // B C A -> rra
        rra(a);
    } 
    else if (a->array[2] > a->array[0] && a->array[0] > a->array[1])
    {
        // C A B -> ra
        ra(a);
    } 
    else if (a->array[2] > a->array[1] && a->array[1] > a->array[0]) 
    {
        // C B A -> sa, rra
        sa(a);
        rra(a);
    }
}


void sort_stacks(t_stack *a, t_stack *b)
{
    while (a->top > 2)  // 3 eleman kalana kadar devam et
    {
        int min_index = find_min_index(a);

        if (min_index == a->top)
            pb(a, b);  // Eğer min zaten en üstteyse, direkt aktar
        else
        {
            if (min_index < a->top / 2)
            {
                while (min_index--)
                    rra(a);
                rra(a);
            }
            else
            {
                min_index = a->top - min_index;
                while (min_index--)
                    ra(a);
            }
            pb(a, b);
        }
    }

    sort_three(a);  // Son 3 elemanı sıralayın

    while (b->top >= 0) // Tüm elemanları geri taşı
        pa(a, b);
}


// Push_swap ana fonksiyonu
void push_swap(t_stack *a, t_stack *b)
{
    sort_stacks(a, b);

    // Sıralanmış yığını yazdırma
    //display(a);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Kullanım: %s <sayılar>\n", argv[0]);
        return 1;
    }

    t_stack *a = create_stack(argc - 1);
    t_stack *b = create_stack(argc - 1);

    for (int i = 1; i < argc; i++)  // argv[1] en üstte olacak
    {
        push(a, atoi(argv[i]));
    }

    push_swap(a, b);

    // Yığınları serbest bırakma
    free(a->array);
    free(b->array);
    free(a);
    free(b);

    return 0;
}