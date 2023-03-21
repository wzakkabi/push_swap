/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:30:04 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/21 17:07:49 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(int *sort, t_stack *a)
{
	int	x;
	int	swap;
	int	test;

	x = ((test = 0), -1);
	while (++x < a->len)
		sort[x] = a->arr[x];
	x = 0;
	while (x < a->len - 1)
	{
		if (sort[x] > sort[x + 1] && x < a->len)
		{
			swap = sort[x];
			sort[x] = sort[x + 1];
			sort[x + 1] = swap;
			x = 0;
			test++;
		}
		else
			x++;
	}
	if (test == 0)
		exit(0);
}

void	ft_counter(int *first, int *last, t_stack *a)
{
	if (a->len == 2)
	{
		sa(a);
		exit(0);
	}
	else if (a->len <= 3)
	{
		*first = 0;
		*last = 1;
	}
	else if (a->len <= 10)
	{
		*first = 0;
		*last = 1;
	}
	else if (a->len <= 100)
	{
		*first = 0;
		*last = 15;
	}
	else
	{
		*first = 0;
		*last = 45;
	}
}

int	postion(t_stack *b, int *sort)
{
	int	x;

	x = 0;
	while (x < b->len)
	{
		if (b->arr[x] == sort[b->len - 1])
			break ;
		x++;
	}
	return (x);
}

void	ft_b_to_a(t_stack *a, t_stack *b, int *sort)
{
	int	x;

	x = 0;
	while (b->len)
	{
		x = postion(b, sort);
		if (x < (b->len / 2))
		{
			while (x != 0)
			{
				rb(b);
				x--;
			}
			pa(a, b);
		}
		else
		{
			while (x != b->len)
			{
				rrb(b);
				x++;
			}
			pa(a, b);
		}
	}
}

void	range(t_stack *a, t_stack *b, int *sort)
{
	int	cntr;
	int	lst_cntr;
	int	len;

	len = a->len;
	ft_counter(&cntr, &lst_cntr, a);
	while (a->len)
	{
		if ((a->arr[0] >= sort[cntr] && a->arr[0] <= sort[lst_cntr]))
		{
			pb(a, b);
			if (lst_cntr < len - 1)
				cntr = ((lst_cntr++), cntr + 1);
		}
		else if (a->arr[0] < sort[cntr])
		{
			pb(a, b);
			rb(b);
			if (lst_cntr < len - 1)
				cntr = ((lst_cntr++), cntr + 1);
		}
		else if (a->arr[0] > sort[lst_cntr])
			ra(a);
	}
	ft_b_to_a(a, b, sort);
}
