/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:28:18 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/22 00:26:23 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str, t_stack *aa, t_stack *bb)
{
	int			x;
	long int	a;
	int			y;

	y = 1;
	a = 0;
	x = 0;
	while ((str[x] >= 9 && str[x] <= 13) || str[x] == 32)
		x++;
	if (str[x] == '-' || str[x] == '+')
	{
		if (str[x] == '-')
			y = -1;
		x++;
	}
	while (str[x] >= '0' && str[x] <= '9')
		a = a * 10 + (str[x++] - 48);
	if ((a * y) > 2147483647 || (a * y) < -2147483648)
	{
		write(2, "Error\n", 6);
		free_all(aa, bb);
	}
	return (a * y);
}
