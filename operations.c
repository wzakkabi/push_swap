/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:07:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/23 01:51:41 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int	swap;

	swap = 0;
	if (a->len > 1)
	{
		swap = a->arr[0];
		a->arr[0] = a->arr[1];
		a->arr[1] = swap;
		write(1, "sa\n", 3);
	}
}

void	sb(t_stack *b)
{
	int	nm_swap;

	nm_swap = 0;
	if (b->len > 1)
	{
		nm_swap = b->arr[0];
		b->arr[0] = b->arr[1];
		b->arr[1] = nm_swap;
		write(1, "sb\n", 3);
	}
}

void	ss(t_stack *a, t_stack *b)
{
	int	swap;

	swap = 0;
	if (a->len > 1)
	{
		swap = a->arr[0];
		a->arr[0] = a->arr[1];
		a->arr[1] = swap;
	}
	if (b->len > 1)
	{
		swap = b->arr[0];
		b->arr[0] = b->arr[1];
		b->arr[1] = swap;
	}
	write(1, "ss\n", 3);
}

void	pa(t_stack *a, t_stack *b)
{
	int	x;
	int	swap;
	int	swap_first;

	x = 0;
	if (b->len > 0)
	{
		swap = ((swap_first = b->arr[x + 1]), b->arr[0]);
		while (x < b->len)
		{
			b->arr[x] = swap_first;
			x++;
			swap_first = b->arr[x + 1];
		}
		b->len--;
		x = a->len;
		while (x >= 0)
		{
			a->arr[x + 1] = a->arr[x];
			x--;
		}
		swap_first = ((a->arr[0] = swap), a->arr[0]);
		a->len++;
		write(1, "pa\n", 3);
	}
}

void	pb(t_stack *a, t_stack *b)
{
	int	x;
	int	swap;
	int	swap_first;

	x = 0;
	if (a->len > 0)
	{
		swap = ((swap_first = a->arr[x + 1]), a->arr[0]);
		while (x < a->len)
		{
			a->arr[x] = swap_first;
			x++;
			swap_first = a->arr[x + 1];
		}
		a->len--;
		x = b->len;
		while (x >= 0)
		{
			b->arr[x + 1] = b->arr[x];
			x--;
		}
		b->arr[0] = ((swap_first = b->arr[0]), swap);
		b->len++;
		write(1, "pb\n", 3);
	}
}
