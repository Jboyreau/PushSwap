/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 06:12:12 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/29 06:38:35 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "bonus.h"

static char	ft_is_sort(long long int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size - 1)
		if (*(tab + i) > *(tab + i + 1))
			return (1);
	return (0);
}

static void	make_list(t_stack *s, unsigned int i, int j)
{
	(*s).fa = malloc(sizeof(t_lst) * (*s).size_tab);
	(*s).alloc = (*s).fa;
	(*((*s).fa + i)).data = *((*s).tab + (j--));
	(*(*s).fa).prev = 0;
	(*(*s).fa).next = (*s).fa + i + 1;
	while ((++i) < (*s).size_tab - 1)
	{
		(*((*s).fa + i)).data = *((*s).tab + (j--));
		(*((*s).fa + i)).prev = (*s).fa + i - 1;
		(*((*s).fa + i)).next = (*s).fa + i + 1;
	}
	(*((*s).fa + i)).data = *((*s).tab);
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
		return (write(2, "OK\n", 3), free(*tab), -1);
	return (size_tab);
}

static void	ft_read_apply(t_stack *s)
{
	char	action;
	char	save;
	char	read_size;
	int		n;
	char	tab[4];

	n = 1;
	ft_set(tab);
	read_size = 4;
	save = 0;
	while (n)
	{
		ft_read(&read_size, tab, &save, &n);
		if (n == 0)
			break ;
		action = ft_check_buffer(tab);
		if (action == 0)
			return (write(2, "Error\n", 6), (void)0);
		ft_set(tab);
		ft_apply_bonus(s, action);
	}
	ft_valid_ornot((*s).fa, (*s).fb);
}

int	main(int argc, char **argv)
{
	t_stack			s;

	s.size_tab = ft_checknset(&(s.tab), argv, argc);
	if (s.size_tab == (unsigned int)(-1))
		return (0);
	make_list(&s, 0, (s.size_tab - 1));
	if (s.alloc == 0)
		return (free(s.tab), 0);
	ft_read_apply(&s);
	return (free(s.tab), free(s.alloc), 0);
}
