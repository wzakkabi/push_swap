/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:01:53 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/16 01:24:57 by wzakkabi         ###   ########.fr       */
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


void ra(t_stack *a);
void rb(t_stack *b);
int check(int len, char **p);
void malloc_stack(t_stack *a, t_stack *b, int ac, char **av);
void    sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void    pb(t_stack *a, t_stack *b);

#endif
