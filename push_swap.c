#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Stack yapısı
typedef struct s_stack
{
    int *array;  // Yığındaki elemanları tutan dizi
    int top;     // Yığındaki en üst elemanın indeksini tutar
} t_stack;

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

// Stack oluşturma fonksiyonu
t_stack *create_stack(int size)
{
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));  // Stack için bellek ayırma
    stack->array = (int *)malloc(size * sizeof(int));     // Yığın dizisi için bellek ayırma
    stack->top = -1;  // Yığının başlangıç durumu, yani boş
    return stack;
}

// Stack'e eleman ekleme fonksiyonu
void push(t_stack *stack, int value)
{
    stack->array[++stack->top] = value;  // Yeni elemanı yığının en üstüne ekle
}

// Stack'ten eleman çıkarma fonksiyonu
int pop(t_stack *stack)
{
    return stack->array[stack->top--];  // Yığının en üst elemanını çıkar ve geri döndür
}

// Swap işlemi: Yığının üstteki iki elemanını takas yapma
void swap(t_stack *stack)
{
    if (stack->top < 1) return;  // Yığın tek elemanlıysa işlem yapma
    int temp = stack->array[stack->top];  // Geçici değişken oluştur
    stack->array[stack->top] = stack->array[stack->top - 1];  // Yığındaki üstteki iki elemanı takas et
    stack->array[stack->top - 1] = temp;
}

// Stack üzerinde sa işlemi (swap)
void sa(t_stack *a)
{
    swap(a);  // Swap işlemi uygula
    printf("sa\n");  // Yığını göster
}

// Stack üzerinde sb işlemi (swap)
void sb(t_stack *b)
{
    swap(b);  // Swap işlemi uygula
    printf("sb\n");  // Yığını göster
}

// Stack üzerinde ss işlemi (her iki yığın için swap)
void ss(t_stack *a, t_stack *b)
{
    swap(a);  // Yığın A üzerinde swap
    swap(b);  // Yığın B üzerinde swap
    printf("ss\n");  // Yığınları göster
}

// Stack'e eleman taşıma (A -> B)
void pa(t_stack *a, t_stack *b)
{
    if (b->top < 0) return;  // Eğer B yığını boşsa, işlem yapma
    push(a, pop(b));  // B'deki elemanı A'ya taşı
    printf("pa\n");  // Yığını göster
}

// Stack'e eleman taşıma (B -> A)
void pb(t_stack *a, t_stack *b)
{
    if (a->top < 0) return;  // Eğer A yığını boşsa, işlem yapma
    push(b, pop(a));  // A'daki elemanı B'ye taşı
    printf("pb\n");  // Yığını göster
}

// Yığın üzerinde rotate işlemi (her elemanı bir sağa kaydırma)
void rotate(t_stack *stack)
{
    if (stack->top < 1) return;  // Eğer yığın tek elemanlıysa, işlem yapma
    int temp = stack->array[stack->top];  // Geçici değişken oluştur
    for (int i = stack->top; i > 0; i--)  // Yığındaki her elemanı bir sağa kaydır
    {
        stack->array[i] = stack->array[i - 1];
    }
    stack->array[0] = temp;  // Son elemanı en başa taşı
}

// Stack üzerinde ra işlemi (rotate)
void ra(t_stack *a)
{
    rotate(a);  // Rotate işlemi uygula
    printf("ra\n");  // Yığını göster
}

// Stack üzerinde rb işlemi (rotate)
void rb(t_stack *b)
{
    rotate(b);  // Rotate işlemi uygula
    printf("rb\n");  // Yığını göster
}

// Stack üzerinde rr işlemi (her iki yığın için rotate)
void rr(t_stack *a, t_stack *b)
{
    rotate(a);  // Yığın A üzerinde rotate
    rotate(b);  // Yığın B üzerinde rotate
    printf("rr\n");  // Yığınları göster
}

// Yığın üzerinde reverse rotate işlemi (her elemanı bir sola kaydırma)
void rev_rotate(t_stack *stack)
{
    if (stack->top < 1) return;  // Eğer yığın tek elemanlıysa, işlem yapma
    int temp = stack->array[0];  // Geçici değişken oluştur
    for (int i = 0; i < stack->top; i++)  // Yığındaki her elemanı bir sola kaydır
    {
        stack->array[i] = stack->array[i + 1];
    }
    stack->array[stack->top] = temp;  // İlk elemanı sona taşı
}

// Stack üzerinde rra işlemi (reverse rotate)
void rra(t_stack *a)
{
    rev_rotate(a);  // Reverse rotate işlemi uygula
    printf("rra\n");  // Yığını göster
}

// Stack üzerinde rrb işlemi (reverse rotate)
void rrb(t_stack *b)
{
    rev_rotate(b);  // Reverse rotate işlemi uygula
    printf("rrb\n");  // Yığını göster
}

// Stack üzerinde rrr işlemi (her iki yığın için reverse rotate)
void rrr(t_stack *a, t_stack *b)
{
    rev_rotate(a);  // Yığın A üzerinde reverse rotate
    rev_rotate(b);  // Yığın B üzerinde reverse rotate
    printf("rrr\n");  // Yığınları göster
}

// Yığın A'nın sıralı olup olmadığını kontrol eder
int is_sorted(t_stack *a)
{
    for (int i = 0; i < a->top; i++)  // Yığındaki her elemanı kontrol et
    {
        if (a->array[i] > a->array[i + 1])  // Eğer sıralı değilse
            return 0;  // Yığın sıralı değil
    }
    return 1;  // Yığın sıralı
}

// Yığındaki en küçük elemanın indeksini bulur
int find_min_index(t_stack *stack)
{
    int min_index = 0;
    for (int i = 1; i <= stack->top; i++)  // Yığındaki her elemanı kontrol et
    {
        if (stack->array[i] < stack->array[min_index])  // Eğer daha küçükse
            min_index = i;  // Min indeksi güncelle
    }
    return min_index;  // En küçük elemanın indeksi
}

// Yığındaki en büyük elemanın indeksini bulur
int find_max_index(t_stack *stack)
{
    int max_index = 0;
    for (int i = 0; i <= stack->top; i++)  // Yığındaki her elemanı kontrol et
    {
        if (stack->array[i] > stack->array[max_index])  // Eğer daha büyükse
            max_index = i;  // Max indeksi güncelle
    }
    return max_index;  // En büyük elemanın indeksi
}

// Üç elemanı sıralama fonksiyonu
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

// B'deki uygun indeksin bulunması
int find_target_index(t_stack *stack, int value)
{
    int i;
    int best_index = -1;

    for (i = 0; i <= stack->top; i++)
    {
        if (stack->array[i] < value)  
        {   
            if (best_index < i) 
                best_index = i;
        }
    }
    if (best_index == -1) 
        best_index = find_max_index(stack);
    
    return best_index;
}

// B'ye taşınma maliyetini hesaplar
int calculate_cost(t_stack *a, t_stack *b, int index)
{
    int cost = 0;
    int b_target_index = find_target_index(b, a->array[index]);  

    if (index <= a->top / 2)
        cost += index + 1;  
    else
        cost += (a->top - index);  

    if (b_target_index <= b->top / 2)
        cost += b_target_index + 1;  
    else
        cost += (b->top - b_target_index);

    return cost;
}

// En düşük maliyetli elemanı bulur
int find_cheapest_index(t_stack *a, t_stack *b)
{
    int min_cost = 99999;
    int cheapest_index = 0;

    for (int i = 0; i <= a->top; i++)  // Tüm elemanları incele
    {
        int cost = calculate_cost(a, b, i);  // Maliyeti hesapla
        if (cost < min_cost)
        {
            min_cost = cost;  // Eğer daha düşükse, güncelle
            cheapest_index = i;  // En ucuz elemanın indeksini sakla
        }
    }
    
    return cheapest_index;  // En ucuz elemanın indeksi
}

// Verilen indeksle yığını döndürme
void end_rotation_a(t_stack *a, int index)
{
    while (a->top > index && index >=0)  
    {
        if (index < a->top / 2)
        {
            rra(a);  
            index--;
        }
        else
        {
            ra(a);  
            index++;
        }
    }
}

void end_rotation_b(t_stack *b, int index)
{
    while (b->top > index && index >= 0)
    {
        if (index < b->top / 2)
        {
            rrb(b);  
            index--;
        }
        else
        {
            rb(b);  
            index++;
        }
    }
}

// En düşük maliyetli elemanı B'ye taşır
void move_to_b(t_stack *a, t_stack *b)
{
    int cheapest_index = find_cheapest_index(a, b);  // En ucuz indeksi bul
    int b_target_index = find_target_index(b, a->array[cheapest_index]);  // B'deki hedefi bul

    //printf("Cheapest: %d [%d]  b target: %d [%d]\n", a->array[cheapest_index], cheapest_index, b->array[b_target_index], b_target_index);

    end_rotation_a(a, cheapest_index);  // Yığının A kısmındaki dönüşü yap
    end_rotation_b(b, b_target_index);  // Yığının B kısmındaki dönüşü yap

    pb(a, b);  // Elemanı B'ye taşı
}

// Türk algoritmasıyla sıralama işlemi
void sort_stacks(t_stack *a, t_stack *b)
{
    while (a->top >= 0)  // 3 eleman kalana kadar işlemi devam ettir
        move_to_b(a, b);  // En ucuz elemanı bul ve taş

    //sort_three(a);  // Kalan 3 elemanı sırala

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

// Ana sıralama fonksiyonu
void push_swap(t_stack *a, t_stack *b)
{
    if (a->top > 2)
        pb(a, b);  // B'ye iki eleman taşı
    if (a->top > 2)
        pb(a, b);
    sort_stacks(a, b);  // Yığınları sıralayın

    // Yığınları yazdır
    //display(a);
}

// Ana fonksiyon
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Kullanım: %s <sayılar>\n", argv[0]);
        return 1;
    }

    t_stack *a = create_stack(argc - 1);  // A yığını oluştur
    t_stack *b = create_stack(argc - 1);  // B yığını oluştur

    for (int i = 1; i < argc; i++) {
        push(a, atoi(argv[i]));
    }

    push_swap(a, b);  // Push_swap fonksiyonunu çağır

    // Yığınları serbest bırak
    free(a->array);
    free(b->array);
    free(a);
    free(b);

    return 0;
}
