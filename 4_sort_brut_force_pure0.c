/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_sort_brut_force_5_less12_0.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:24:49 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/28 01:25:54 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

#define COMB_MAX 36
#define MAX_ELEM 6

static char	ft_try(t_stack *s, t_lst *stacks, char *tab, int i)
{
	char	j;

	j = 1;
	while ((*(tab + i) < 9))
	{
		j = ft_test0(stacks, s, tab);
		if (j == 0)
			break ;
		ft_init02(stacks, s, -1);
		++(*(tab + i));
	}
	return (j);
}

static void	ft_rules(char *tab, int i)
{
	if (*(tab + i - 1) == 2 && *(tab + i) == 1)
		*(tab + i) = 3;
	else if (*(tab + i - 1) == 1 && *(tab + i) == 1)
		*(tab + i) = 3;
	else if (*(tab + i - 1) == 3 && *(tab + i) == 2)
		*(tab + i) = 4;
	else if (*(tab + i - 1) == 4 && *(tab + i) == 3)
		*(tab + i) = 5;
	else if (*(tab + i - 1) == 7 && *(tab + i) == 4)
		*(tab + i) = 6;
	else if (*(tab + i - 1) == 5 && *(tab + i) == 6)
		*(tab + i) = 8;
	else if (*(tab + i - 1) == 6 && *(tab + i) == 7)
	{
		*(tab + i) = 1;
		*(tab + i - 1) = 7;
	}
	else if (*(tab + i - 1) == 8 && *(tab + i) == 5)
		*(tab + i) = 7;
	else
		++(*(tab + i));
}

static char	ft_inc0(t_stack s, char *tab, int len, char j)
{
	int		i;
	t_lst	stacks[MAX_ELEM];

	ft_init0(tab, stacks, &s, len);
	i = len - 1;
	while (j)
	{
		j = ft_try(&s, stacks, tab, i);
		if (j == 0)
			break ;
		while ((i > -1) && (*(tab + i) >= 8))
			--i;
		if ((i < 0))
			break ;
		if (i > 0)
			ft_rules(tab, i);
		else
			++(*(tab + i));
		while (++i < len)
			*(tab + i) = 1;
		--i;
	}
	return (j);
}

static void	ft_display0(int data)
{
	if (data == 1)
		return (write(1, "pa\n", 3), (void)0);
	if (data == 2)
		return (write(1, "pb\n", 3), (void)0);
	if (data == 3)
		return (write(1, "sa\n", 3), (void)0);
	if (data == 4)
		return (write(1, "sb\n", 3), (void)0);
	if (data == 5)
		return (write(1, "ra\n", 3), (void)0);
	if (data == 6)
		return (write(1, "rb\n", 3), (void)0);
	if (data == 7)
		return (write(1, "rra\n", 4), (void)0);
	if (data == 8)
		return (write(1, "rrb\n", 4), (void)0);
}

void	ft_brut_force(t_stack *s, int i, char j)
{
	char	tab[COMB_MAX];
	int		len;

	len = 1;
	while (j)
	{
		*tab = 1;
		j = ft_inc0(*s, tab, len, 1);
		len++;
	}
	while (*(tab + (++i)))
		if (ft_apply0(&((*s).fa), s, *(tab + i)))
			ft_display0(*(tab + i));
}
