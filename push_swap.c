/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:26:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/16 01:29:57 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



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
    t_cnt   cnt;
    char    **split;

    cnt.x = ((cnt.y = 0),(cnt.i = 0), 0);
    a->len = 0;
    while(++cnt.x < ac)
        a->len = ft_word(av[cnt.x], ' ') + a->len;
    a->arr = (int *)malloc(sizeof(int) * (a->len));
    b->arr = (int *)malloc(sizeof(int) * (a->len));
    cnt.x = 0;
    while(++cnt.x < ac)
    {
        b->len = ft_word(av[cnt.x], ' ');
        if(b->len == 1)
            a->arr[cnt.i++] = ft_atoi(av[cnt.x]);
        else
        {
            split = ft_split(av[cnt.x], ' ');
            cnt.y = -1;
            while(split[++cnt.y])
                a->arr[cnt.i++] = ft_atoi(split[cnt.y]);
            free_malloc(split);
        }
        b->len = 0;
    }
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
void    test_number_doplicate(t_stack *a)
{
    int x = 0;
    int y = 0;
    int def;
    while(x < a->len)
    {
        def = a->arr[x];
        y = x + 1;
        while(y < a->len)
        {
            if(a->arr[y] == def)
            {
                write(1, "Error\n", 6);
                exit(1);
            }
            y++;
        }
        x++;
    }
}

void range(t_stack *a, t_stack *b)
{
    
}

int main(int ac, char **av)
{
    t_stack a;
    t_stack b;
    //t_cnt   cnt;
    int x;
    if(ac > 1)
    {
        x = check(ac, av);
        if(x == 0)
        {
            write(1, "Error\n", 6);
            return 0;
        }
        else
            {
                malloc_stack(&a , &b, ac, av);
                test_number_doplicate(&a);
                range(&a, &b);
            }
            x = 0;
    }
    return 0;
}