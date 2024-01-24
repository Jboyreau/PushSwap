/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_sort_brut_force_5_less12_1.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:39:50 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/28 00:55:23 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define COMB_MAX 12

char	ft_issort0(t_lst *fa, t_stack *s)
{
	unsigned int	i;

	i = 1;
	while ((*fa).next != 0)
	{
		if ((*fa).data < (*(*fa).next).data)
			return (1);
		fa = (*fa).next;
		++i;
	}
	if (i < (*s).size_tab)
		return (1);
	return (0);
}

char	ft_apply0(t_lst **fa, t_stack *s, int data)
{
	if (data == 1 && (*s).fb != 0)
		return (ft_pa(fa, &((*s).fb), s), 1);
	if (data == 2 && *fa != 0)
		return (ft_pb(fa, &((*s).fb), s), 1);
	if (data == 3 && *fa != 0 && *fa != (*s).la)
		return (ft_s(fa, s, 'a'), 1);
	if (data == 4 && (*s).fb != 0 && (*s).fb != (*s).lb)
		return (ft_s(&((*s).fb), s, 'b'), 1);
	if (data == 5 && *fa != 0 && *fa != (*s).la)
		return (ft_r(fa, s, 'a'), 1);
	if (data == 6 && (*s).fb != 0 && (*s).fb != (*s).lb)
		return (ft_r(&((*s).fb), s, 'b'), 1);
	if (data == 7 && *fa != 0 && *fa != (*s).la)
		return (ft_revr(fa, s, 'a'), 1);
	if (data == 8 && (*s).fb != 0 && (*s).fb != (*s).lb)
		return (ft_revr(&((*s).fb), s, 'b'), 1);
	return (0);
}

char	ft_test0(t_lst *fa, t_stack *s, char *tab)
{
	int	i;

	i = -1;
	while (*(tab + (++i)) > 0)
	{
		if (ft_apply0(&fa, s, *(tab + i)))
			if (fa)
				if (ft_issort0(fa, s) == 0)
					return (0);
	}
	return (1);
}

void	ft_init02(t_lst *stacks, t_stack *s, unsigned int i)
{
	(*s).fb = 0;
	(*s).lb = 0;
	while ((++i) < (*s).size_tab)
	{
		(*(stacks + i)).data = (*((*s).fa + i)).data;
		if (i > 0)
			(*(stacks + i)).prev = stacks + i - 1;
		else if (i == 0)
			(*(stacks + i)).prev = 0;
		if (i < (*s).size_tab - 1)
			(*(stacks + i)).next = stacks + i + 1;
		else if (i == (*s).size_tab - 1)
			(*(stacks + i)).next = 0;
	}
	(*s).la = stacks + ((*s).size_tab - 1);
}

void	ft_init0(char *tab, t_lst *stacks, t_stack *s, int len)
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
	ft_init02(stacks, s, -1);
}
