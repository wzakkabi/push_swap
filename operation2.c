/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 01:28:09 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/23 02:13:11 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int	x;
	int	swap;

	x = 0;
	if (a->len > 1)
	{
		swap = a->arr[0];
		while (x < a->len)
		{
			a->arr[x] = a->arr[x + 1];
			x++;
		}
		a->arr[a->len - 1] = swap;
		write(1, "ra\n", 3);
	}
}

void	rb(t_stack *b)
{
	int	x;
	int	swap;

	x = 0;
	if (b->len > 1)
	{
		swap = b->arr[0];
		while (x < b->len)
		{
			b->arr[x] = b->arr[x + 1];
			x++;
		}
		b->arr[b->len - 1] = swap;
		write(1, "rb\n", 3);
	}
}

void	rr(t_stack *a, t_stack *b)
{
	int	x;
	int	swap;

	if (b->len > 1)
	{
		swap = ((x = 0), b->arr[0]);
		while (x < b->len)
		{
			b->arr[x] = b->arr[x + 1];
			x++;
		}
		b->arr[b->len - 1] = swap;
	}
	x = 0;
	if (a->len > 1)
	{
		swap = a->arr[0];
		while (x < a->len)
		{
			a->arr[x] = a->arr[x + 1];
			x++;
		}
		a->arr[a->len - 1] = swap;
	}
	write(1, "rr\n", 3);
}

void	rra(t_stack *a, int ww)
{
	int	x;
	int	swap;
	int	swap2;
	int	swap_last;

	x = 0;
	if (a->len > 1)
	{
		swap_last = a->arr[a->len - 1];
		swap = a->arr[x];
		while (x < a->len)
		{
			swap2 = a->arr[x + 1];
			a->arr[x + 1] = swap;
			swap = swap2;
			x++;
		}
		a->arr[0] = swap_last;
	}
	if (ww == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, int ww)
{
	int	x;
	int	swap;
	int	swap2;
	int	swap_last;

	x = 0;
	if (b->len > 1)
	{
		swap_last = b->arr[b->len - 1];
		swap = b->arr[x];
		while (x < b->len)
		{
			swap2 = b->arr[x + 1];
			b->arr[x + 1] = swap;
			swap = swap2;
			x++;
		}
		b->arr[0] = swap_last;
	}
	if (ww == 1)
		write(1, "rrb\n", 4);
}
