/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 19:52:31 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/22 19:54:28 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	malloc_stack(t_stack *a, t_stack *b, int ac, char **av)
{
	t_cnt	cnt;
	char	**split;

	cnt.x = ((cnt.y = 0), (cnt.i = 0), (a->len = 0), 0);
	while (++cnt.x < ac)
		a->len = ft_word(av[cnt.x], ' ') + a->len;
	a->arr = (int *)malloc(sizeof(int) * (a->len));
	b->arr = (int *)malloc(sizeof(int) * (a->len));
	cnt.x = 0;
	while (++cnt.x < ac)
	{
		b->len = ft_word(av[cnt.x], ' ');
		if (b->len == 1)
			a->arr[cnt.i++] = ft_atoi(av[cnt.x], a, b);
		else
		{
			split = ft_split(av[cnt.x], ' ');
			cnt.y = -1;
			while (split[++cnt.y])
				a->arr[cnt.i++] = ft_atoi(split[cnt.y], a, b);
			free_malloc(split);
		}
		b->len = 0;
	}
}

void	free_malloc(char **p)
{
	int x;

	x = 0;
	while (p[x])
		free(p[x++]);
	free(p);
}


void free_all(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(b->arr);
	exit(1);
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