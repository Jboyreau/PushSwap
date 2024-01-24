/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_sort_turbo_insertion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 10:15:50 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/28 04:08:01 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	ft_costsort_b(t_lst *l, t_lst *f, int data)
{
	int	rotations;
	int	reverse_rotations;

	rotations = 0;
	while (l)
	{
		if ((*l).data == data)
			break ;
		rotations++;
		l = (*l).prev;
	}
	reverse_rotations = 0;
	while (f)
	{
		if ((*f).data == data)
			break ;
		reverse_rotations++;
		f = (*f).next;
	}
	if (rotations < reverse_rotations)
		return (1);
	return (0);
}

static char	ft_insertion(t_stack *s, int *index, int i)
{
	char	test;

	test = 0;
	while ((*(*s).lb).data != *((*s).tab + i))
	{
		if ((*(*s).lb).data == *((*s).tab + i - 1))
		{
			test = 1;
			ft_pa_print(&(*s).fa, &(*s).fb, s, (*s).ac);
		}
		else if (ft_costsort_b((*s).lb, (*s).fb, *((*s).tab + i)))
			ft_r_print(&(*s).fb, s, 'b', (*s).ac);
		else
			ft_revr_print(&(*s).fb, s, 'b', (*s).ac);
	}
	ft_pa_print(&(*s).fa, &(*s).fb, s, (*s).ac);
	if (test == 1)
		--(*index);
	return (test);
}

static char	ft_check_presence(t_lst *lb, long long int *tab, int i, int len)
{
	int	j;
	int	nb;
	int	k;
	int	save_i;

	j = -1;
	nb = 0;
	save_i = i;
	while (lb && (++j) < len && i > -1)
	{
		k = -1;
		i = save_i;
		while (lb && (++k) < len && i > -1)
		{
			if ((*lb).data == *(tab + i))
				++nb;
			--i;
		}
		lb = (*lb).prev;
		if (lb == 0)
			break ;
	}
	if (nb == len)
		return (nb);
	return (0);
}

static char	ft_is_sub(t_lst *lb, long long int *tab, int i)
{
	int	nb;
	int	len;

	len = 1;
	while (++len < 6)
	{
		nb = ft_check_presence(lb, tab, i, len);
		if (nb == len)
			return (nb);
	}
	return (0);
}

void	ft_turbo_insertion(t_stack *s, int i)
{
	int	n;

	i = (*s).size_tab;
	while ((--i) > -1)
	{
		n = ft_is_sub((*s).lb, (*s).tab, i);
		if (n)
		{
			if (ft_brut_force_to_a(s, -1, 1, n))
			{
				if (ft_insertion(s, &i, i) == 1)
					ft_s_print(&(*s).fa, s, 'a', (*s).ac);
			}
			else
				i -= n - 1;
		}
		else
		{
			if (ft_insertion(s, &i, i) == 1)
				ft_s_print(&(*s).fa, s, 'a', (*s).ac);
		}
		if ((*s).lb == 0)
			break ;
	}
}
