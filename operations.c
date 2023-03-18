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
		write(1,"sa", 2);
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
		write(1,"sb", 2);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1,"ss", 2);
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
		write(1,"pa", 2);
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
		write(1,"pb", 2);
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
		write(1,"ra", 2);
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
		write(1,"rb", 2);
	}
}

void rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1,"rr", 2);
}

void rra(t_stack *a)
{
	int x;
	int swap, swap2,swap_last;
	x  = 0;
	if(a->len > 1)
	{
		swap_last = a->arr[a->len - 1];
		swap = a->arr[x];
		while(x < a->len)
		{
			swap2 = a->arr[x + 1];
			a->arr[x + 1] = swap;
			swap = swap2;
			x++;
		}
		a->arr[0] = swap_last;
		write(1,"rra", 3);
	}
}

void rrb(t_stack *b)
{
	int x;
	int swap, swap2,swap_last;
	x  = 0;
	if(b->len > 1)
	{
		swap_last = b->arr[b->len - 1];
		swap = b->arr[x];
		while(x < b->len)
		{
			swap2 = b->arr[x + 1];
			b->arr[x + 1] = swap;
			swap = swap2;
			x++;
		}
		b->arr[0] = swap_last;
		write(1,"rrb", 3);
	}
}

void rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1,"rrr", 3);
}