/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:26:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/11 01:56:14 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>

int check(int len, char **p)
{
    int x;;
    int y;
    y = 1;
    while(y < len)
    {
        x = 0;
        while(p[y][x])
        {
            if ((p[y][x] <= '9' && p[y][x] >= '0') || p[y][x] == ' ')
                x++;
            else
                return 0;
        }
        y++;
    } 
    return 1;
}

int main(int ac, char **av)
{
    int x;
    if(ac > 1)
    {
        x = check(ac, av);
        if(x == 0)
        {
            write(1, "error", 5);
            return 0;
        }
    }
    return 0;
}