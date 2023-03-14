/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:26:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/14 01:56:51 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"


void free_malloc(char **p)
{
    int x = 0;
    while(p[x])
        free(p[x++]);
    free(p);
}
void malloc_stack(t_stack *a, t_stack *b, int ac, char **av)
{
    int x = 1;
    int y = 0;
    int i = 0;
    char **split;
    while(x < ac)
    {
        a->len = ft_word(av[x], ' ');
        x++;
    }
    write(1, , 2);
    a->arr = (int *)malloc(sizeof(int) * (a->len));
    // b->arr = (int *)malloc(sizeof(int) * (a->len));
    x = 0;
    write(1, "8\n", 2);
    write(1, "1\n", 2);
    while(x < ac)
    {
        b->len = ft_word(av[x], ' ');
        if(b->len == 1)
            a->arr[i++] = ft_atoi(av[x]);
        else
        {
            write(1, "1\n", 2);
            split = ft_split(av[x], ' ');
            y = 0;
            while(split[y])
            {
                write(1, "2\n", 2);
                a->arr[i] = ft_atoi(split[y]);
                write(1, "3\n", 2);
                i++;
                y++;
            }
            free_malloc(split);
        }
        x++;
        b->len = 0;
    }
    x = 0;
    while(x < 10)
        printf("%d\n", a->arr[x]);
    free(a->arr);
}


int check(int len, char **p)
{
    int x;;
    int y;

    y = 1;
    while(y < len)
    {
        x = 0;
        while(p[y][x] == ' ')
            x++;
        if(p[y][x] == '\0')
            return 0;
        while(p[y][x])
        {
            if ((p[y][x] <= '9' && p[y][x] >= '0') || p[y][x] == ' ')
                x++;
            else if ((p[y][x] == '+' && p[y][x + 1] <= '9' && p[y][x + 1] >= '0') || (p[y][x] == '-' && p[y][x + 1] <= '9' && p[y][x + 1] >= '0'))
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
    t_stack *a;
    t_stack *b;

    int x;
    if(ac > 1)
    {
        x = check(ac, av);
        if(x == 0)
        {
            write(1, "error", 5);
            return 0;
        }
        else
            {
                malloc_stack(a , b, ac, av);
            }
    }
    return 0;
}