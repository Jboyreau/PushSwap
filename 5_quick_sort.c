/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_quick_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:10:19 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/28 02:18:20 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"
#define DIV 2

static void	ft_divide_block_a(t_stack *s, int i)
{
	while ((*s).la)
	{
		(*s).size_stack = ft_lstlen((*s).la) - 1;
		(*s).size_block = ft_size_block((*s).p_tab, (*s).size_stack);
		if ((*s).size_block == 0)
			while ((*s).la)
				ft_pb_print(&(*s).fa, &(*s).fb, s, (*s).ac);
		else if ((*s).size_block == 1)
			(*s).ip += 1;
		else if ((i++) % 2 == 0)
			(*s).ip += ((*s).size_block / DIV);
		else
			(*s).ip += (*s).size_block;
		*((*s).p_tab + (*s).ip) = 1;
		while (ft_tofind_a((*s).la, *((*s).tab + (*s).ip)))
		{
			if ((*(*s).la).data < *((*s).tab + (*s).ip))
				ft_pb_print(&(*s).fa, &(*s).fb, s, (*s).ac);
			else if (ft_costr_a((*s).la, (*s).fa, *((*s).tab + (*s).ip)))
				ft_r_print(&(*s).fa, s, 'a', (*s).ac);
			else
				ft_revr_print(&(*s).fa, s, 'a', (*s).ac);
		}
	}
}

static void	ft_divide_block_b(t_stack *s)
{
	while ((*s).lb)
	{
		(*s).size_stack = ft_lstlen((*s).lb) - 1;
		(*s).size_block = ft_size_block((*s).p_tab, (*s).size_stack);
		if ((*s).size_block == 0)
			while ((*s).lb)
				ft_pa_print(&(*s).fa, &(*s).fb, s, (*s).ac);
		else if ((*s).size_block == 1)
			(*s).ip = (*s).size_stack - 1;
		else
			(*s).ip = ((*s).size_stack - ((*s).size_block / DIV));
		*((*s).p_tab + (*s).ip) = 1;
		while (ft_tofind_b((*s).lb, *((*s).tab + (*s).ip)))
		{
			if ((*(*s).lb).data > *((*s).tab + (*s).ip))
				ft_push_a(s);
			else if (ft_costr_b((*s).lb, (*s).fb, *((*s).tab + (*s).ip)))
				ft_r_print(&(*s).fb, s, 'b', (*s).ac);
			else
				ft_revr_print(&(*s).fb, s, 'b', (*s).ac);
		}
	}
}

static void	ft_divide_a(t_stack *s, int i, int div)
{
	(*s).ip = 0;
	(*s).size_stack = 2;
	while ((*s).la)
	{
		(*s).size_stack = ft_lstlen((*s).la);
		if ((*s).size_stack < (unsigned int)div)
			while ((*s).la)
				ft_pb_print(&(*s).fa, &(*s).fb, s, (*s).ac);
		else
			(*s).ip += ((*s).size_stack / div);
		*((*s).p_tab + (*s).ip) = 1;
		while (ft_tofind_a((*s).la, *((*s).tab + (*s).ip)))
		{
			if ((*(*s).la).data < *((*s).tab + (*s).ip))
				ft_push_b(s, i);
			else if (ft_costr_a((*s).la, (*s).fa, *((*s).tab + (*s).ip)))
				ft_r_print(&(*s).fa, s, 'a', (*s).ac);
			else
				ft_revr_print(&(*s).fa, s, 'a', (*s).ac);
		}
		++i;
	}
}

char	ft_quick_sort(t_stack *s)
{
	int	div;

	div = 2;
	if ((*s).size_tab < 101)
		div = 3;
	(*s).p_tab = malloc(sizeof(int) * (*s).size_tab);
	if ((*s).p_tab == 0)
		return (write(2, "Error\n", 6), 1);
	ft_p_tab_init((*s).p_tab, (*s).size_tab);
	ft_divide_a(s, 0, div);
	while (ft_is_presort((*s).p_tab, (*s).size_tab))
	{
		ft_divide_block_b(s);
		ft_divide_block_a(s, 0);
	}
	return (free((*s).p_tab), ft_turbo_insertion(s, 0), 0);
}
