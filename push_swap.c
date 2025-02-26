#include "push_swap.h"



// Yığını yazdırma fonksiyonu
void display(t_stack *a)
{
    printf("Sorted Stack: ");
    for (int i = 0; i <= a->top; i++)  // Yığındaki her elemanı yazdır
    {
        printf("%d ", a->array[i]);
    }
    printf("\n");
}

// Verilen indeksle yığını döndürme
void end_rotation(t_stack *a, t_stack *b, int index_a, int index_b)
{
    // Eğer her iki indeks de üst yarıda ise, çift yönlü döndür
    if (index_a < a->top / 2 && index_b < b->top / 2)
    {
        while ((a->top > index_a && index_a >= 0) && (b->top > index_b && index_b >= 0))
        {
            rrr(a, b);  
            index_a--;
            index_b--;
        }
    }
    // Eğer her iki indeks de alt yarıda ise, ileri yönde döndür
    else if (index_a >= a->top / 2 && index_b >= b->top / 2)
    {
        while ((a->top > index_a && index_a >= 0) && (b->top > index_b && index_b >= 0))
        {
            rr(a, b);  
            index_a++;
            index_b++;
        }
    }
    
    while (a->top > index_a && index_a >= 0)  
    {
        if (index_a < a->top / 2)
        {
            rra(a);  
            index_a--;
        }
        else
        {
            ra(a);  
            index_a++;
        }
    }
    while (b->top > index_b && index_b >= 0)
    {
        if (index_b < b->top / 2)
        {
            rrb(b);  
            index_b--;
        }
        else
        {
            rb(b);  
            index_b++;
        }
    }
}


// En düşük maliyetli elemanı B'ye taşır
void move_to_b(t_stack *a, t_stack *b)
{
    int cheapest_index = find_cheapest_index(a, b);  // En ucuz indeksi bul
    int b_target_index = find_target_index(b, a->array[cheapest_index]);  // B'deki hedefi bul

    printf("Cheapest: %d [%d]  b target: %d [%d]\n", a->array[cheapest_index], cheapest_index, b->array[b_target_index], b_target_index);

    end_rotation(a, b, cheapest_index, b_target_index);
    // Yığının A kısmındaki dönüşü yap
    // Yığının B kısmındaki dönüşü yap

    pb(a, b);  // Elemanı B'ye taşı
}

// Türk algoritmasıyla sıralama işlemi
void sort_stacks(t_stack *a, t_stack *b)
{
    while (a->top >= 0)  // 3 eleman kalana kadar işlemi devam ettir
        move_to_b(a, b);  // En ucuz elemanı bul ve taş

    while (b->top >= 0) // B yığını boşalana kadar elemanları geri taşı
        pa(a, b);

    int max_index = find_max_index(a);
    //printf("max: %d [%d]\n", a->array[max_index],max_index);
    while (max_index != 0 && max_index >= 0 && max_index <= a->top)
    {
        if (max_index < a->top / 2)
        {
            rra(a);  
            max_index--;
        }
        else
        {
            ra(a);  
            max_index++;
        }
    }
}

// Üç elemanı sıralama fonksiyonu
void sort_three(t_stack *a) 
{
    if (a->array[0] > a->array[2] && a->array[2] > a->array[1]) // A C B -> sa
        sa(a);
    else if (a->array[1] > a->array[0] && a->array[0] > a->array[2]) // B A C -> sa, ra
    {
        sa(a);
        ra(a);
    } 
    else if (a->array[1] > a->array[2] && a->array[2] > a->array[0]) // B C A -> rra
        rra(a);
    else if (a->array[2] > a->array[0] && a->array[0] > a->array[1]) // C A B -> ra
        ra(a);
    else if (a->array[2] > a->array[1] && a->array[1] > a->array[0]) // C B A -> sa, rra
    {
        sa(a);
        rra(a);
    }
}

// Ana sıralama fonksiyonu
void push_swap(t_stack *a, t_stack *b)
{
    if (!is_sorted(a))
    {
        if (a->top == 1)
            ra(a);
        else if (a->top == 2)
            sort_three(a);
        else
        {
            if (a->top > 2)
                pb(a, b);  // B'ye iki eleman taşı
            if (a->top > 2)
                pb(a, b);
            sort_stacks(a, b);  // Yığınları sıralayın
        }
}
    // Yığınları yazdır
    display(a);
}