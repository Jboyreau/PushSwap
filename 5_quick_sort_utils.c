/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_quick_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:04:16 by jboyreau          #+#    #+#             */
/*   Updated: 2023/02/01 09:44:50 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_p_tab_init(char *p_tab, int size)
{
	int	i;

	i = 0;
	*p_tab = 1;
	while ((++i) < size)
		*(p_tab + i) = 0;
}

char	ft_tofind_a(t_lst *l, int data)
{
	while (l)
	{
		if ((*l).data < data)
			return (1);
		l = (*l).prev;
	}
	return (0);
}

char	ft_tofind_b(t_lst *l, int data)
{
	while (l)
	{
		if ((*l).data > data)
			return (1);
		l = (*l).prev;
	}
	return (0);
}

char	ft_costr_a(t_lst *l, t_lst *f, int data)
{
	int	rotations;
	int	reverse_rotations;

	rotations = 0;
	while (l)
	{
		if ((*l).data < data)
			break ;
		rotations++;
		l = (*l).prev;
	}
	reverse_rotations = 0;
	while (f)
	{
		if ((*f).data < data)
			break ;
		reverse_rotations++;
		f = (*f).next;
	}
	if (rotations <= reverse_rotations)
		return (1);
	return (0);
}

char	ft_costr_b(t_lst *l, t_lst *f, int data)
{
	int	rotations;
	int	reverse_rotations;

	rotations = 0;
	while (l)
	{
		if ((*l).data > data)
			break ;
		rotations++;
		l = (*l).prev;
	}
	reverse_rotations = 0;
	while (f)
	{
		if ((*f).data > data)
			break ;
		reverse_rotations++;
		f = (*f).next;
	}
	if (rotations <= reverse_rotations)
		return (1);
	return (0);
}
