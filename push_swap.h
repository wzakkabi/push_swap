/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzakkabi <wzakkabi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 01:01:53 by wzakkabi          #+#    #+#             */
/*   Updated: 2023/03/23 01:56:16 by wzakkabi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*arr;
	int	len;
}	t_stack;

//libft function
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char const *s, char c);
int		ft_word(char const *s, char c);
int		ft_atoi(const char *str, t_stack *a, t_stack *b);
size_t	ft_strlen(const char *s);

typedef struct s_cnt
{
	int	x;
	int	y;
	int	i;
}	t_cnt;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a, int ww);
void	rrb(t_stack *b, int ww);
void	rrr(t_stack *a, t_stack *b);

//push_swap function
void	malloc_stack(t_stack *a, t_stack *b, int ac, char **av);
int		check(int len, char **p, int x, int y);
void	free_malloc(char **p);
void	test_number_doplicate(t_stack *a, t_stack *b);
int		postion(t_stack *b, int *sort);
void	ft_counter(int *last, t_stack *a, t_stack *b, int *sort);
void	range(t_stack *a, t_stack *b, int *sort);
void	ft_sort(int *sort, t_stack *a, t_stack *b);
void	ft_b_to_a(t_stack *a, t_stack *b, int *sort);
void	ft_sort3(t_stack *a);
void	ft_sort5(t_stack *a, t_stack *b);
void	free_all(t_stack *a, t_stack *b, int *sort);
void	push_swap(t_stack *a, t_stack *b, int ac, char **av);
#endif
