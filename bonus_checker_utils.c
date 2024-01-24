/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 07:41:36 by jboyreau          #+#    #+#             */
/*   Updated: 2023/02/01 09:46:00 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"
#include "bonus.h"

void	ft_set(char *tab)
{
	int	i;

	i = -1;
	while ((++i) < 4)
		*(tab + i) = 0;
}

void	ft_read(char *read_size, char *tab, char *save, int *n)
{
	if (*read_size == 4)
		*n = read(0, tab, *read_size);
	else
	{
		*n = read(0, tab + 1, *read_size);
		*tab = *save;
	}
	if (*(tab + 3) != '\n' && *(tab + 3) != '\0')
	{
		*save = *(tab + 3);
		*read_size = 3;
	}
	else
		*read_size = 4;
}

void	ft_valid_ornot(t_lst *fa, t_lst *fb)
{
	if (fb != 0 || fa == 0)
		return (write(1, "KO\n", 3), (void)0);
	if ((*fa).next == 0)
		return (write(1, "KO\n", 3), (void)0);
	while ((*fa).next)
	{
		if ((*fa).data < (*(*fa).next).data)
			return (write(1, "KO\n", 3), (void)0);
		fa = (*fa).next;
	}
	return (write(1, "OK\n", 3), (void)0);
}

char	ft_check_buffer(char *tab)
{
	if (tab[0] == 'p' && tab[1] == 'a' && tab[2] == '\n')
		return (1);
	if (tab[0] == 'p' && tab[1] == 'b' && tab[2] == '\n')
		return (2);
	if (tab[0] == 's' && tab[1] == 'a' && tab[2] == '\n')
		return (3);
	if (tab[0] == 's' && tab[1] == 'b' && tab[2] == '\n')
		return (4);
	if (tab[0] == 'r' && tab[1] == 'a' && tab[2] == '\n')
		return (5);
	if (tab[0] == 'r' && tab[1] == 'b' && tab[2] == '\n')
		return (6);
	if (tab[0] == 'r' && tab[1] == 'r' && tab[2] == 'a' && tab[3] == '\n')
		return (7);
	if (tab[0] == 'r' && tab[1] == 'r' && tab[2] == 'b' && tab[3] == '\n')
		return (8);
	if (tab[0] == 's' && tab[1] == 's' && tab[2] == '\n')
		return (9);
	if (tab[0] == 'r' && tab[1] == 'r' && tab[2] == '\n')
		return (10);
	if (tab[0] == 'r' && tab[1] == 'r' && tab[2] == 'r' && tab[3] == '\n')
		return (11);
	return (0);
}

void	ft_apply_bonus(t_stack *s, char action)
{
	if (action == 1)
		ft_pa_safe(s);
	if (action == 2)
		ft_pb_safe(s);
	if (action == 3)
		ft_sa_safe(s);
	if (action == 4)
		ft_sb_safe(s);
	if (action == 5)
		ft_ra_safe(s);
	if (action == 6)
		ft_rb_safe(s);
	if (action == 7)
		ft_rra_safe(s);
	if (action == 8)
		ft_rrb_safe(s);
	if (action == 9)
		ft_ss_safe(s);
	if (action == 10)
		ft_rr_safe(s);
	if (action == 11)
		ft_rrr_safe(s);
}
