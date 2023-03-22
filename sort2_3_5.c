/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2_3_5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:30:04 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/22 19:54:23 by wzakkabi         ###   ########.fr       */
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

void	ft_sort5_help(t_stack *a, t_stack *b, int *sort, int x)
{
	while (a->len != 3)
	{
		x = postion(a, sort);
		if (x <= a->len / 2)
		{
			while (x != 0)
			{
				ra(a);
				x--;
			}
			pb(a, b);
		}
		else
		{
			if (x > a->len / 2)
			{
				while (x < a->len)
				{
					rra(a);
					x++;
				}
				pb(a, b);
			}
		}
	}
}

void	ft_sort5(t_stack *a, t_stack *b)
{
	int	*sort;

	sort = malloc(a->len * sizeof(int));
	ft_sort(sort, a);
	ft_sort5_help(a, b, sort, 0);
	ft_sort3(a);
	while (b->len)
	{
		pa(a, b);
		ra(a);
	}
}

void	ft_sort3(t_stack *a)
{
	if (a->arr[0] > a->arr[1] && a->arr[2] > a->arr[0]
		&& a->arr[2] > a->arr[1])
		sa(a);
	else if (a->arr[0] > a->arr[1] && a->arr[0] > a->arr[2]
		&& a->arr[1] > a->arr[2])
	{
		sa(a);
		rra(a);
	}
	else if (a->arr[0] > a->arr[2] && a->arr[0] > a->arr[1]
		&& a->arr[1] < a->arr[2])
		ra(a);
	else if (a->arr[0] < a->arr[1] && a->arr[1] > a->arr[2]
		&& a->arr[0] < a->arr[2])
	{
		sa(a);
		ra(a);
	}
	else if (a->arr[0] < a->arr[1] && a->arr[0] > a->arr[2]
		&& a->arr[2] < a->arr[1])
		rra(a);
}

void	ft_counter(int *last, t_stack *a, t_stack *b)
{
	if (a->len == 2)
	{
		sa(a);
		exit(0);
	}
	else if (a->len <= 3)
	{
		ft_sort3(a);
		exit(0);
	}
	else if (a->len <= 5)
	{
		ft_sort5(a, b);
		exit(0);
	}
	else if (a->len <= 15)
		*last = 2;
	else if (a->len <= 100)
		*last = 15;
	else
		*last = 30;
}




