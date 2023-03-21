/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 00:26:03 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/21 00:54:33 by wzakkabi         ###   ########.fr       */
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

int postion(t_stack *b, int *sort)
{
    int x = 0;
     while(x < b->len)
    {
        if(b->arr[x] == sort[b->len - 1])
            break;
        x++;
    }
    return x;
}



void range(t_stack *a, t_stack *b, int *sort)
{
    int x = 0;
    int cntr = 0;
    int lst_cntr = 1;
    int size;
    int len = a->len;
    while(x < a->len)
    {
        if((a->arr[x] >= sort[cntr] && a->arr[x] <= sort[lst_cntr]))
        {
                pb(a, b); 
            if(lst_cntr < len - 1)
            {
            cntr++;
            lst_cntr++;
            }
        }
        else if (a->arr[x] < sort[cntr])
        {
            pb(a,b);
            rb(b);
            if(lst_cntr < len - 1)
            {
            cntr++;
            lst_cntr++;
            }
        }
        else if(a->arr[x] > sort[lst_cntr])
            ra(a);
    }
    x = 0;
    while(b->len)
    {
        x = postion(b , sort);
        if(x < (b->len / 2))
        {
            while(x != 0)
            {
                rb(b);
                x--;
            }
            pa(a,b);
        }
        else
        {
            while(x != b->len)
            {
                rrb(b);
                x++;
            }
            pa(a,b);
        }
    }
}
void ft_sort(int *sort, t_stack *a)
{
    int x = 0;
    int swap;
    while(x < a->len)
    {
        sort[x] = a->arr[x];
        x++;
    }
    x = 0;
    while(x < a->len - 1)
    {
        if(sort[x] > sort[x + 1] && x < a->len)
        {
            swap = sort[x];
            sort[x] = sort[x + 1];
            sort[x + 1] = swap;
            x = 0;
        }
        else
            x++;
    }
}

int main(int ac, char **av)
{
    t_stack a;
    t_stack b;
    int *sort;
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
                sort = malloc(a.len * sizeof(int));
                ft_sort(sort, &a);
                range(&a, &b , sort);
            }
            x = 0;
            while(x < a.len)
                printf("aa = %d\n", a.arr[x++]);

            // x = 0;
            // while(x < b.len)
            //     printf("bb = %d\n", b.arr[x++]);
    }
    return 0;
}