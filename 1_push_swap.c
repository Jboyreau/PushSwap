/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:25:58 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/25 01:03:53 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "push_swap.h"

static char	ft_is_sort(long long int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
		if (*(tab + i) > *(tab + i + 1))
			return (1);
	return (0);
}

static void	ft_sort_tab(long long int *tab, int size_tab)
{
	int	i;
	int	i_min;
	int	j;
	int	min;
	int	save;

	i = -1;
	while ((++i) < size_tab)
	{
		j = i;
		min = *(tab + i);
		while ((++j) < size_tab)
		{
			if (*(tab + j) < min)
				i_min = j;
			if (*(tab + j) < min)
				min = *(tab + j);
		}
		if (min != *(tab + i))
		{
			save = *(tab + i_min);
			*(tab + i_min) = *(tab + i);
			*(tab + i) = save;
		}
	}
}

static void	make_list(t_stack *s, unsigned int i, int j)
{
	(*s).fa = malloc(sizeof(t_lst) * (*s).size_tab);
	(*s).alloc = (*s).fa;
	(*((*s).fa + i)).data = *((*s).tab + (j--));
	(*((*s).fa + i)).pivot = 0;
	(*(*s).fa).prev = 0;
	(*(*s).fa).next = (*s).fa + i + 1;
	while ((++i) < (*s).size_tab - 1)
	{
		(*((*s).fa + i)).data = *((*s).tab + (j--));
		(*((*s).fa + i)).pivot = 0;
		(*((*s).fa + i)).prev = (*s).fa + i - 1;
		(*((*s).fa + i)).next = (*s).fa + i + 1;
	}
	(*((*s).fa + i)).data = *((*s).tab);
	(*((*s).fa + i)).pivot = 0;
	(*((*s).fa + i)).prev = (*s).fa + i - 1;
	(*((*s).fa + i)).next = 0;
	(*s).la = (*s).fa + i;
	(*s).fb = 0;
	(*s).lb = 0;
}

static int	ft_checknset(long long int **tab, char **argv, int argc)
{
	int	size_tab;

	if (argc <= 1)
		return (-1);
	if (argc == 2)
		size_tab = ft_word_count(*(argv + 1), *(argv + 1), tab, 0);
	else
		size_tab = ft_str_count(argv + 1, argc - 1, tab);
	if (size_tab == -1 || ft_check_double(*tab, size_tab))
	{
		if (tab != 0)
			return (free(*tab), write(2, "Error\n", 6), -1);
		else
			return (-1);
	}
	if (size_tab == 0)
		return (-1);
	if (ft_is_sort(*tab, size_tab) == 0)
		return (free(*tab), -1);
	return (size_tab);
}

int	main(int argc, char **argv)
{
	unsigned int	i;
	t_stack			s;

	s.size_tab = ft_checknset(&(s.tab), argv, argc);
	if (s.size_tab == (unsigned int)(-1))
		return (0);
	make_list(&s, 0, (s.size_tab - 1));
	if (s.alloc == 0)
		return (free(s.tab), 0);
	ft_sort_tab(s.tab, s.size_tab);
	s.ac.actions = malloc(s.size_tab * s.size_tab);
	if (s.ac.actions == 0)
		return (free(s.tab), free(s.alloc), 0);
	i = -1;
	while ((++i) < (s.size_tab * s.size_tab))
		*(s.ac.actions + i) = 0;
	i = 0;
	s.ac.index = &i;
	if (s.size_tab < 7)
		ft_brut_force(&s, -1, 1);
	if (s.size_tab > 6)
		if (ft_quick_sort(&s))
			return (free(s.tab), free(s.alloc), free(s.ac.actions), 0);
	return (ft_show(s.ac), free(s.tab), free(s.alloc), free(s.ac.actions), 0);
}
