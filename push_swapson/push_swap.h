/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:48:35 by ekibar            #+#    #+#             */
/*   Updated: 2025/03/19 23:23:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*array;
	int	top;
}		t_stack;

char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	ft_error(void);
int		ft_strlen(char *str);
void	free_stack(t_stack *a, t_stack *b);
void	free_argv(char **argv);
int		ft_is_numeric(char **argv);
int		is_duplicate(char **argv, int argc);
int		is_valid_int(char **argv);
void	error_control(int argc, char **argv);
long	ft_atoi(const char *str);
char	**ft_split(char *str, char separator);
t_stack	*create_stack(int size);
int		is_sorted(t_stack *a);
int		find_min_index(t_stack *stack);
int		find_max_index(t_stack *stack);
int		find_target_index_a(t_stack *a, int value);
int		find_target_index_b(t_stack *b, int value);
int		calculate_cost(t_stack *a, t_stack *b, int index);
int		find_cheapest_index(t_stack *a, t_stack *b);
void	rr_rrr(t_stack *a, t_stack *b, int *index_a, int *index_b);
void	end_rotation_a(t_stack *a, int *index_a);
void	end_rotation_b(t_stack *b, int *index_b);
void	move_to_b(t_stack *a, t_stack *b);
void	move_to_a(t_stack *a, t_stack *b);
void	sort_stacks(t_stack *a, t_stack *b);
void	sort_three(t_stack *a);
void	push_swap(t_stack *a, t_stack *b);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	swap(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	rotate(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rev_rotate(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif