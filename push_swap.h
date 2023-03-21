/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:01:53 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/21 17:08:13 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

#include "./ll/libft.h"
#include <stdio.h>
#include <unistd.h>

typedef struct  s_stack
{
	int *arr;
	int len;
}   t_stack;

typedef struct  s_cnt
{
	int x;
	int y;
	int i;
}   t_cnt;


void    sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	malloc_stack(t_stack *a, t_stack *b, int ac, char **av);
int		check(int len, char **p);
void free_malloc(char **p);
void    test_number_doplicate(t_stack *a);
int postion(t_stack *b, int *sort);
void	ft_counter(int *first, int *last, t_stack *a);
void range(t_stack *a, t_stack *b, int *sort);
void ft_sort(int *sort, t_stack *a);
void	ft_b_to_a(t_stack *a, t_stack *b, int *sort);
#endif
