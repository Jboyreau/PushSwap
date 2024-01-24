/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_sort_brut_force_to_a.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:52:50 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/28 03:38:52 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

#define COMB_MAX 12

static void	ft_rules(char *tab, int i)
{
	if (*(tab + i - 1) == 2 && *(tab + i) == 1)
		(*(tab + i)) = 3;
	else if (*(tab + i - 1) == 3 && *(tab + i) == 2)
		(*(tab + i)) = 4;
	else if (*(tab + i - 1) == 5 && *(tab + i) == 3)
		(*(tab + i)) = 5;
	else if (*(tab + i - 1) == 4 && *(tab + i) == 4)
	{
		*(tab + i) = 1;
		*(tab + i - 1) = 5;
	}
	else
		++(*(tab + i));
}

static char	ft_inc_2(char *tab, int *i, int len)
{
	while ((*i > -1) && (*(tab + (*i)) >= 5))
		--(*i);
	if ((*i < 0))
		return (0);
	if (*i > 0)
		ft_rules(tab, *i);
	else
		++(*(tab + (*i)));
	while (++(*i) < len)
		*(tab + (*i)) = 1;
	--(*i);
	return (1);
}

static char	ft_inc(t_stack s, char *tab, int len, char j)
{
	int		i;
	t_lst	stacks[8];
	t_lst	*lb_cpy;

	i = 0;
	while ((++i) < s.n)
		s.lb = (*(s.lb)).prev;
	lb_cpy = s.lb;
	ft_init(tab, stacks, &s, len);
	i = len - 1;
	while (j)
	{
		while ((*(tab + i) < 6))
		{
			j = ft_test(stacks, &s, tab);
			if (j == 0)
				break ;
			ft_init2(stacks, &s, lb_cpy, 0);
			++(*(tab + i));
		}
		if (j == 0 || ft_inc_2(tab, &i, len) == 0)
			break ;
	}
	return (j);
}

static void	ft_display(t_lst **fb, t_stack *s, int data)
{
	if ((data == 1) && (*fb != 0) && ((*(*s).lb).pivot != -2))
		return (ft_pa_print(&(*s).fa, fb, s, (*s).ac), (void)0);
	if ((data == 2) && ((*s).fa != 0)
		&& ((*s).fa != (*s).la) && ((*(*s).fa).pivot != -2))
		return (ft_s_print(&(*s).fa, s, 'a', (*s).ac), (void)0);
	if ((data == 3) && (*fb != 0) && (*fb != (*s).lb))
		if (((*(*s).lb).pivot != -2) && ((*(*(*s).lb).prev).pivot != -2))
			return (ft_s_print(fb, s, 'b', (*s).ac), (void)0);
	if ((data == 4) && (*fb != 0) && (*fb != (*s).lb)
		&& ((*(*s).lb).pivot != -2))
		return (ft_r_print(fb, s, 'b', (*s).ac), (void)0);
	if ((data == 5) && (*fb != 0) && (*fb != (*s).lb) && ((**fb).pivot != -2))
		return (ft_revr_print(fb, s, 'b', (*s).ac), (void)0);
}

char	ft_brut_force_to_a(t_stack *s, int i, char j, char n)
{
	char	tab[COMB_MAX];
	int		len;

	len = n;
	(*s).n = n;
	while (j)
	{
		*tab = 1;
		j = ft_inc(*s, tab, len, 1);
		len++;
		if (len > 10)
			return (1);
	}
	while (*(tab + (++i)))
		ft_display(&((*s).fb), s, *(tab + i));
	return (0);
}
