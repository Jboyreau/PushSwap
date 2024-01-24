/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_sort_brut_force_to_a2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:53:20 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/28 03:54:29 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

#define COMB_MAX 12

char	ft_issort(t_lst *fa, t_stack *s)
{
	int	i;

	i = 1;
	if ((*fa).pivot != -2)
		return (1);
	fa = (*fa).next;
	if (fa)
	{
		while ((*fa).next != 0)
		{
			if ((*fa).data < (*(*fa).next).data)
				return (1);
			fa = (*fa).next;
			++i;
		}
	}
	if (i < (*s).n)
		return (1);
	return (0);
}

char	ft_apply(t_lst **fb, t_stack *s, int data)
{
	if ((data == 1) && (*fb != 0) && ((*(*s).lb).pivot != -2))
		return (ft_pa(&(*s).fa, fb, s), 1);
	if ((data == 2) && ((*s).fa != 0) && ((*s).fa != (*s).la)
		&& ((*(*s).fa).pivot != -2))
		return (ft_s(&(*s).fa, s, 'a'), 1);
	if ((data == 3) && (*fb != 0) && (*fb != (*s).lb))
		if (((*(*s).lb).pivot != -2) && ((*(*(*s).lb).prev).pivot != -2))
			return (ft_s(fb, s, 'b'), 1);
	if ((data == 4) && (*fb != 0) && (*fb != (*s).lb)
		&& ((*(*s).lb).pivot != -2))
		return (ft_r(fb, s, 'b'), 1);
	if ((data == 5) && (*fb != 0) && (*fb != (*s).lb)
		&& ((**fb).pivot != -2))
		return (ft_revr(fb, s, 'b'), 1);
	return (0);
}

char	ft_test(t_lst *fb, t_stack *s, char *tab)
{
	int	i;

	i = -1;
	while (*(tab + (++i)) > 0)
	{
		if (ft_apply(&fb, s, *(tab + i)))
			if (ft_issort((*s).fa, s) == 0)
				return (0);
	}
	return (1);
}

void	ft_init2(t_lst *stacks, t_stack *s, t_lst *lb_cpy, int i)
{
	(*stacks).pivot = -2;
	(*stacks).prev = 0;
	(*stacks).next = stacks + 1;
	(*(stacks + 7)).pivot = -2;
	(*(stacks + 7)).prev = 0;
	(*(stacks + 7)).next = 0;
	while ((++i) < (*s).n + 1)
	{
		(*(stacks + i)).data = (*lb_cpy).data;
		(*(stacks + i)).pivot = 0;
		(*(stacks + i)).prev = stacks + i - 1;
		if (i < (*s).n)
			(*(stacks + i)).next = stacks + i + 1;
		else
			(*(stacks + i)).next = 0;
		lb_cpy = (*lb_cpy).next;
	}
	(*s).la = stacks + 7;
	(*s).fa = stacks + 7;
	(*s).lb = stacks + (*s).n;
}

void	ft_init(char *tab, t_lst *stacks, t_stack *s, int len)
{
	int	i;

	i = 0;
	while ((++i) < len)
		*(tab + i) = 1;
	while (i < COMB_MAX)
	{
		*(tab + i) = 0;
		++i;
	}
	ft_init2(stacks, s, (*s).lb, 0);
}
