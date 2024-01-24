/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_show.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 04:11:29 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/28 04:15:44 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

static void	ft_display(char data)
{
	if (data == 1)
		return ((void)write(1, "pa\n", 3));
	if (data == 2)
		return ((void)write(1, "pb\n", 3));
	if (data == 3)
		return ((void)write(1, "sa\n", 3));
	if (data == 4)
		return ((void)write(1, "sb\n", 3));
	if (data == 5)
		return ((void)write(1, "ra\n", 3));
	if (data == 6)
		return ((void)write(1, "rb\n", 3));
	if (data == 7)
		return ((void)write(1, "rra\n", 4));
	if (data == 8)
		return ((void)write(1, "rrb\n", 4));
	if (data == 9)
		return ((void)write(1, "ss\n", 3));
	if (data == 10)
		return ((void)write(1, "rr\n", 3));
	if (data == 11)
		return ((void)write(1, "rrr\n", 4));
}

static void	ft_clean(char *actions)
{
	unsigned int	i;

	i = 0;
	while (*(actions + i + 1))
	{
		if ((*(actions + i) == 3 && *(actions + i + 1) == 4)
			|| (*(actions + i) == 4 && *(actions + i + 1) == 3))
		{
			*(actions + i) = 9;
			*(actions + i + 1) = 0;
		}
		if ((*(actions + i) == 5 && *(actions + i + 1) == 6)
			|| (*(actions + i) == 6 && *(actions + i + 1) == 5))
		{
			*(actions + i) = 10;
			*(actions + i + 1) = 0;
		}
		if ((*(actions + i) == 7 && *(actions + i + 1) == 8)
			|| (*(actions + i) == 8 && *(actions + i + 1) == 7))
		{
			*(actions + i) = 11;
			*(actions + i + 1) = 0;
		}
		++i;
	}
}

void	ft_show(t_actions ac)
{
	unsigned int	i;
	unsigned int	max;

	ft_clean(ac.actions);
	max = *(ac.index) + 1;
	i = -1;
	while ((++i) < max)
		if (*(ac.actions + i) != 0)
			ft_display (*(ac.actions + i));
}
