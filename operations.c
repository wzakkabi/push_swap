/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:07:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/11 21:20:07 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void sa(t_stack *a)
{
	int swap = 0;
	
	if(a->len > 1)
	{
		swap = a->arr[0];
		a->arr[0] = a->arr[1];
		a->arr[1] = swap;
	}
}

void	sb(t_stack *b)
{
	int nm_swap = 0;
	
	if(b->len > 1)
	{
		nm_swap = b->arr[0];
		b->arr[0] = b->arr[1];
		b->arr[1] = nm_swap;
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	int x = a->len - 1;
	if(b->len > 1)
	{
		while(x != 0)
		{
			a->arr[x + 1] = a->arr[x];
			x--;
		}
		a->arr[0] = b->arr[0];
		a->len++;
		x = 0;
		while(x < b->len)
		{
			b->arr[x] = b->arr[x + 1];
			x++;
		}
		b->len--;
	}
	x = 0;
	while(x < a->len)
		printf("a->arr =%d\n", a->arr[x++]);
	printf("a-len  = %d\n", a->len);
	printf("b-len = %d\n", b->len);
	x = 0;
	while(x < b->len)
		printf("b->arr = %d\n", b->arr[x++]);
}