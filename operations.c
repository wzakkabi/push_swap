/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:07:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/16 01:29:37 by wzakkabi         ###   ########.fr       */
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
	int x;
	int swap;
	if(b->len >= 1)
	{
		swap = a->arr[0];
		x = a->len - 1;
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
		a->arr[1] = swap;
		b->len--;
	}
}

void pb(t_stack *a, t_stack *b)
{
	int x;
	int swap;
	if(a->len >= 1)
	{
		swap = b->arr[0];
		x = b->len - 1;
		while(x != 0)
		{
			b->arr[x + 1] = b->arr[x];
			x--;
		}
		b->arr[0] = a->arr[0];
		b->len++;
		x = 0;
		while(x < a->len)
		{
			a->arr[x] = a->arr[x + 1];
			x++;
		}
		b->arr[1] = swap;
		a->len--;
	}
}

void ra(t_stack *a)
{
	int x;
	int swap;

	x = 0;
	if(a->len > 1)
	{
		swap = a->arr[0];
		while(x < a->len)
		{
			a->arr[x] = a->arr[x + 1];
			x++;
		}
		a->arr[a->len - 1] = swap;
	}
}

void rb(t_stack *b)
{
	int x;
	int swap;

	x = 0;
	if(b->len > 1)
	{
		swap = b->arr[0];
		while(x < b->len)
		{
			b->arr[x] = b->arr[x + 1];
			x++;
		}
		b->arr[b->len - 1] = swap;
	}
}

void rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void rra(t_stack *a)
{
	int x;
	int swap;
	x  = 0;
	if(a->len > 1)
	{
		
	}
}