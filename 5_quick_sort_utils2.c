/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_quick_sort_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:31:57 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/28 02:32:26 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_is_presort(char *p_tab, int size)
{
	int	max;
	int	j;
	int	save;

	max = 0;
	save = 0;
	j = -1;
	while (++j < size)
	{
		if (*(p_tab + j) == 1)
		{
			if ((j - save) > max)
				max = j - save;
			save = j;
		}
	}
	if (max < 32)
		return (0);
	return (1);
}

int	ft_size_block(char *p_tab, int start)
{
	int	i;

	i = start;
	if (*(p_tab + i) == 1 && i != 0)
		--i;
	while (*(p_tab + i) == 0)
		--i;
	return (start - i);
}

void	ft_push_b(t_stack *s, int i)
{
	int	first;
	int	mid_mid;

	first = (*s).size_tab - (*s).size_stack;
	mid_mid = ((*s).ip - first) / 2;
	if (i == 0 && (*(*s).la).data < *((*s).tab + (*s).ip / 2))
	{
		*((*s).p_tab + ((*s).ip / 2)) = 1;
		ft_pb_print(&(*s).fa, &(*s).fb, s, (*s).ac);
		ft_r_print(&(*s).fb, s, 'b', (*s).ac);
	}
	else if ((*(*s).la).data < *((*s).tab + first + mid_mid))
	{
		*((*s).p_tab + first + mid_mid) = 1;
		ft_pb_print(&(*s).fa, &(*s).fb, s, (*s).ac);
		ft_r_print(&(*s).fb, s, 'b', (*s).ac);
	}
	else
		ft_pb_print(&(*s).fa, &(*s).fb, s, (*s).ac);
}

void	ft_push_a(t_stack *s)
{
	int	first;
	int	mid_mid;

	first = (*s).size_stack;
	mid_mid = first - (first - (*s).ip) / 2;
	if ((*(*s).lb).data < *((*s).tab + mid_mid))
	{
		*((*s).p_tab + mid_mid) = 1;
		ft_pa_print(&(*s).fa, &(*s).fb, s, (*s).ac);
		ft_r_print(&(*s).fa, s, 'a', (*s).ac);
	}
	else
		ft_pa_print(&(*s).fa, &(*s).fb, s, (*s).ac);
}

int	ft_lstlen(t_lst *l)
{
	int	i;

	i = 0;
	while (l)
	{
		if ((*l).pivot > -1)
			++i;
		l = (*l).prev;
	}
	return (i);
}
