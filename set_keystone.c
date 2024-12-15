/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_keystone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoolszew <zoolszew@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:44:30 by zoolszew          #+#    #+#             */
/*   Updated: 2024/12/14 08:48:13 by zoolszew         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int *find_keystone(t_keystone *tab, int size, int *block_size, int *i)
{ 
    int	save;
	static int	current_keystone[2];
	int mid;
	int midmid;

	save = *i;
	while (*i < size && (*(tab + *i)).on_off == 1)
		++(*i);
	*i -= (*i == size);
	while (*i < size && (*(tab + *i)).on_off == 0)
		++(*i);
	*i -= (*i == size);
	*block_size = (*i - save);
	mid = *i - *block_size / 3 - *block_size / 6;
	midmid = mid - *block_size / 6;
	(*(tab + *i + mid)).on_off = 1;
	*current_keystone = (*(tab + mid)).num;
	(*(tab + midmid)).on_off = 1;
	*(current_keystone + 1) = (*(tab + midmid)).num;
	*i = mid;
	return (current_keystone);
}

int *find_keystoneB(t_keystone *tab, int size, int *block_size, int *i)
{
    int save;
	static int	current_keystone[2];
	int mid;
	int midmid;
	
	save = *i;
	while (*i > -1 && (*(tab + *i)).on_off == 1)
		--(*i);
	*i += (*i == -1);
	while (*i > -1 && (*(tab + *i)).on_off == 0)
		--(*i);
	*i += (*i == -1);
	*block_size = save - *i;
	mid = *i + *block_size / 2;
	midmid = mid + *block_size / 4;
	(*(tab + *i + mid)).on_off = 1;
	*current_keystone = (*(tab + mid)).num;
	(*(tab + midmid)).on_off = 1;
	*(current_keystone + 1) = (*(tab + midmid)).num;
	*i = mid;
	return (current_keystone);
}

int find_path(int* range, int*rrange, t_array *tab_int, int *current_keystone)
{
	t_list *node;

	*range = 0;
	node = (*tab_int).first_a;
	while (node)
	{
		if ((*node).num <= *current_keystone)
			break ;
		node = (*node).next;
		++(*range);
	}
	if (node == NULL)
		return (1);
	*rrange = 0;
	node = (*tab_int).last_a;
	while (node)
	{
		if ((*node).num <= *current_keystone)
			break ;
		node = (*node).prev;
		++(*rrange);
	}
	return (0);
}

int find_pathB(int* range, int*rrange, t_array *tab_int, int *current_keystone)
{
	t_list *node;

	*range = 0;
	node = (*tab_int).first_b;
	while (node)
	{
		if ((*node).num >= *current_keystone)
			break ;
		node = (*node).next;
		++(*range);
	}
	if (node == NULL)
		return (1);
	*rrange = 0;
	node = (*tab_int).last_b;
	while (node)
	{
		if ((*node).num >= *current_keystone)
			break ;
		node = (*node).prev;
		++(*rrange);
	}
	return (0);
}

void empty_block(int *current_keystone, t_array *tab_int, t_list *first_a, t_list *last_a)
{
	t_list *node;
	int range;
	int rrange;

	find_path(&range, &rrange, tab_int, current_keystone);
	while (1)
	{
		while ((*(*tab_int).first_a).num <= *current_keystone)
		{
			ft_push_b(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
			if ((*(*tab_int).first_b).num < *(current_keystone + 1))
				ft_rb(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
			if ((*tab_int).first_a)
			{
				if ((*(*tab_int).first_a).num > *current_keystone)
					if (find_path(&range, &rrange, tab_int, current_keystone))
						return ;
			}
			else
				return ;
		}
		if (rrange < range)
			ft_rra(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
		else
			ft_ra(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
	}
}

void empty_blockB(int *current_keystone, t_array *tab_int, t_list *first_b, t_list *last_b)
{
	t_list *node;
	int range;
	int rrange;

	find_pathB(&range, &rrange, tab_int, current_keystone);
	while (1)
	{
		while ((*(*tab_int).first_b).num >= *current_keystone)
		{
			ft_push_a(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
			if ((*(*tab_int).first_a).num > *(current_keystone + 1))
				ft_ra(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
			if ((*tab_int).first_b)
			{
				if ((*(*tab_int).first_b).num < *current_keystone)
					if (find_pathB(&range, &rrange, tab_int, current_keystone))
						return ;
			}
			else
				return ;
		}
		if (rrange < range)
			ft_rrb(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
		else
			ft_rb(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
	}
}

void empty_block_no_rb(int *current_keystone, t_array *tab_int, t_list *first_a, t_list *last_a)
{
	t_list *node;
	int range;
	int rrange;

	find_path(&range, &rrange, tab_int, current_keystone);
	while (1)
	{
		while ((*(*tab_int).first_a).num <= *current_keystone)
		{
			ft_push_b(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
			if ((*tab_int).first_a)
			{
				if ((*(*tab_int).first_a).num > *current_keystone)
					if (find_path(&range, &rrange, tab_int, current_keystone))
						return ;
			}
			else
				return ;
		}
		if (rrange < range)
			ft_rra(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
		else
			ft_ra(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
	}
}


void empty_blockB_no_ra(int *current_keystone, t_array *tab_int, t_list *first_b, t_list *last_b)
{
	t_list *node;
	int range;
	int rrange;

	find_pathB(&range, &rrange, tab_int, current_keystone);
	while (1)
	{
		while ((*(*tab_int).first_b).num >= *current_keystone)
		{
			ft_push_a(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
			if ((*tab_int).first_b)
			{
				if ((*(*tab_int).first_b).num < *current_keystone)
					if (find_pathB(&range, &rrange, tab_int, current_keystone))
						return ;
			}
			else
				return ;
		}
		if (rrange < range)
			ft_rrb(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
		else
			ft_rb(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
	}
}

void	findTarget(t_array *tab_int, int num, t_target *t)
{
	int range;
	int rrange;	
	t_list *node;

	range = 0;
	node = (*tab_int).first_b;
	while (node)
	{
		if ((*node).num == num)
			break ;
		node = (*node).next;
		++range;
	}
	rrange = 0;
	node = (*tab_int).last_b;
	while (node)
	{
		if ((*node).num == num)
			break ;
		node = (*node).prev;
		++rrange;
	}
	(*t).num = num;
	if (range < rrange)
	{
		(*t).range = range;
		(*t).op = RB;
	}
	else
	{	
		(*t).range = rrange;
		(*t).op = RRB;
	}
}


void findAndPush(t_target *t, t_array *tab_int)
{
	if ((*t).op == RB)
	{
		while (1)
		{
			if ((*(*tab_int).first_b).num == (*t).num)
			{
				ft_push_a(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
				return ;
			}
			ft_rb(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
		}
	}
	else
	{
		while (1)
		{
			if ((*(*tab_int).first_b).num == (*t).num)
			{
				ft_push_a(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
				return ;
			}
			ft_rrb(&((*tab_int).index_actions), tab_int, (*tab_int).actions);
		}
	}
}

void	ft_insert(t_keystone *tab, int size, t_array *tab_int)
{
	int i;
	int flag;
	t_target t1;
	t_target t2;

	i = size - 1;
	while (i > -1)
	{
		if (i > 1)
		{
			findTarget(tab_int, (*(tab + i)).num, &t1);
			findTarget(tab_int, (*(tab + i - 1)).num, &t2);
			if (t1.range <= t2.range)
				flag = 0;
			else
				flag = 1;
		}
		else
		{
			flag = 0;
			findTarget(tab_int, (*(tab + i)).num, &t1);
		}
		if (flag)
		{
			findAndPush(&t2, tab_int);
			findAndPush(&t1, tab_int);
			ft_swap_a(&((*tab_int).index_actions), (*tab_int).first_a, (*tab_int).actions);
			if ((*tab_int).first_b)
				if ((*(*tab_int).first_b).next)
					if ((*(*tab_int).first_b).num < (*(*(*tab_int).first_b).next).num)
						ft_swap_b(&((*tab_int).index_actions), (*tab_int).first_b, (*tab_int).actions);
			i -= 2;
		}
		else
		{
			findAndPush(&t1, tab_int);
			--i;
		}
	}
}

void sorting_algo(t_array *tab_int)
{
	int *current_keystone;
	int i = (*tab_int).size - 1;
	int j = 0;
	int maxKeystone;

	maxKeystone = (*tab_int).size / 32;
	maxKeystone += (maxKeystone == 0);
	while((*tab_int).first_a)
	{
		current_keystone = find_keystone((*tab_int).tab, (*tab_int).size, (&(*tab_int).block_size), &j);
		empty_block(current_keystone, tab_int, (*tab_int).first_a, (*tab_int).last_a);
		++((*tab_int).count_keystone);
	}
	if ((*tab_int).count_keystone < maxKeystone)
	{
		while ((*tab_int).first_b)
		{
			current_keystone = find_keystoneB((*tab_int).tab, (*tab_int).size, (&(*tab_int).block_size), &i);
			//if ((*tab_int).block_size > 32)
				empty_blockB(current_keystone, tab_int, (*tab_int).first_b, (*tab_int).last_b);
			//else
			//	empty_blockB_no_ra(current_keystone, tab_int, (*tab_int).first_b, (*tab_int).last_b);
			++((*tab_int).count_keystone);
		}
		i = (*tab_int).size - 1;
		j = 0;
		while (1)
		{
			while((*tab_int).first_a)
			{
				current_keystone = find_keystone((*tab_int).tab, (*tab_int).size, (&(*tab_int).block_size), &j);
				empty_block_no_rb(current_keystone, tab_int, (*tab_int).first_a, (*tab_int).last_a);
				++((*tab_int).count_keystone);
			}
			if ((*tab_int).count_keystone < maxKeystone)
			{
				while ((*tab_int).first_b)
				{
					current_keystone = find_keystoneB((*tab_int).tab, (*tab_int).size, (&(*tab_int).block_size), &i);
					empty_blockB_no_ra(current_keystone, tab_int, (*tab_int).first_b, (*tab_int).last_b);
					++((*tab_int).count_keystone);
				}
			}
			else
				break ;
		}
	}
	ft_insert((*tab_int).tab, (*tab_int).size, tab_int);
}
