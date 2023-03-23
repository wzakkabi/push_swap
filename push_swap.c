/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:26:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/23 01:20:01 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check(int len, char **p, int x, int y)
{
	while (y < len)
	{
		x = 0;
		while (p[y][x] == ' ')
			x++;
		if (p[y][x] == '\0')
			return (0);
		while (p[y][x])
		{
			if ((p[y][x] <= '9' && p[y][x] >= '0') || p[y][x] == ' ')
				x++;
			else if ((p[y][x] == '+' && p[y][x + 1] <= '9' && p[y][x + 1] >= '0') || (p[y][x] == '-' && p[y][x + 1] <= '9' && p[y][x + 1] >= '0'))
			{
				if (p[y][x - 1] <= '9' && p[y][x - 1] >= '0')
					return (0);
				x++;
			}
			else
				return (0);
		}
		y++;
	}
	return (1);
}

void range(t_stack *a, t_stack *b, int *sort)
{
	int cntr;
	int lst_cntr;
	int len;

	cntr = ((len = a->len), 0);
	ft_counter(&lst_cntr, a, b, sort);
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

void test_number_doplicate(t_stack *a, t_stack *b)
{
	int x;
	int y;
	int def;

	x = ((y = 0), 0);
	while (x < a->len)
	{
		def = a->arr[x];
		y = x + 1;
		while (y < a->len)
		{
			if (a->arr[y] == def)
			{
				write(2, "Error\n", 6);
				free_all(a, b, NULL);
			}
			y++;
		}
		x++;
	}
}

void push_swap(t_stack *a, t_stack *b, int ac, char **av)
{
	int *sort;

	malloc_stack(a, b, ac, av);
	test_number_doplicate(a, b);
	sort = malloc(a->len * sizeof(int));
	ft_sort(sort, a, b);
	range(a, b, sort);
}

int main(int ac, char **av)
{
	t_stack a;
	t_stack b;
	int x;
	if (ac >= 1)
	{
		x = check(ac, av, 0, 1);
		if (x == 0)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		else
			push_swap(&a, &b, ac, av);
	}
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}
