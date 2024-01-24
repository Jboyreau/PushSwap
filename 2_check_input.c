/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_check_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 02:10:41 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/28 05:52:12 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "push_swap.h"
#define M 2147483647
#define M_ 2147483648

static long long int	ft_atoi_txt(char **txt, char sign, long long int sum)
{
	if (**txt == '-')
		sign *= -1;
	if (**txt == '+' || **txt == '-')
		(*txt)++;
	while (**txt >= '0' && **txt <= '9')
	{
		if (((sum * 10 + **txt - 48) > M && sign > -1)
			|| sum * 10 + **txt - 48 > M_)
			return ((size_t)M + 1);
		sum = sum * 10 + *((*txt)++) - 48;
	}
	return ((sum * sign));
}

static char	ft_checkpm(char *s, char *s2, char m)
{
	if ((*s < '0' || *s > '9') && ((*s != '+') && (*s != '-')))
		return (1);
	if ((*s == '+' || *s == '-'))
		if (*(s + 1) == ' ' || *(s + 1) == '\t' || (*(s + 1) == 0)
			|| (s != s2 && *(s - 1) != 32 && *(s - 1) != '\t')
			|| (s != s2 && m == 1))
			return (1);
	return (0);
}

int	ft_str_count(char **argv, int argc, long long int **tab)
{
	int	i;
	int	j;

	*tab = malloc((argc) * sizeof(long long int));
	if (tab == 0)
		return (0);
	i = -1;
	while ((++i) < argc)
	{
		j = -1;
		while (*(*(argv + i) + (++j)))
			if (ft_checkpm((*(argv + i) + j), (*(argv + i)), 1))
				return (tab = 0, -1);
		if (*(*(argv + i) + j) != 0)
			return (-1);
		*((*tab) + i) = ft_atoi_s(*(argv + i), 1, 0);
		if (*((*tab) + i) > (M))
			return (-1);
	}
	return (i);
}

int	ft_word_count(char *s, char *save, long long int **tab, int i)
{
	while (*s)
	{
		while ((*s == ' ' || *s == '\t') && *s)
			s++;
		if ((*s != ' ' && *s != '\t') && *s)
			i++;
		while ((*s != ' ' && *s != '\t') && *s)
			if (ft_checkpm((++s) - 1, save, 0))
				return (*tab = 0, -1);
	}
	*tab = malloc((i + (i == 0)) * sizeof(long long int));
	if (tab == 0 || i == 0)
		return (-(tab != 0));
	i = 0;
	while (*save)
	{
		while ((*save == ' ' || *save == '\t') && *save)
			save++;
		if ((*save != ' ' && *save != '\t') && *save)
			*((*tab) + (i++)) = ft_atoi_txt(&save, 1, 0);
		if (*((*tab) + i - 1) > (M))
			return (-1);
	}
	return (i);
}

char	ft_check_double(long long int *tab, int size)
{
	int	i;
	int	j;

	i = -1;
	while ((++i) < size)
	{
		j = -1;
		while ((++j) < i)
			if (*(tab + j) == *(tab + i))
				return (1);
	}
	return (0);
}
