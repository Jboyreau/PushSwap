/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_action3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:36:50 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/27 23:40:20 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_actions(char data, t_actions ac)
{
	if (data == 1)
		return (*(ac.actions + *(ac.index)) = 1, ++(*(ac.index)), (void)0);
	if (data == 2)
		return (*(ac.actions + *(ac.index)) = 2, ++(*(ac.index)), (void)0);
	if (data == 3)
		return (*(ac.actions + *(ac.index)) = 3, ++(*(ac.index)), (void)0);
	if (data == 4)
		return (*(ac.actions + *(ac.index)) = 4, ++(*(ac.index)), (void)0);
	if (data == 5)
		return (*(ac.actions + *(ac.index)) = 5, ++(*(ac.index)), (void)0);
	if (data == 6)
		return (*(ac.actions + *(ac.index)) = 6, ++(*(ac.index)), (void)0);
	if (data == 7)
		return (*(ac.actions + *(ac.index)) = 7, ++(*(ac.index)), (void)0);
	if (data == 8)
		return (*(ac.actions + *(ac.index)) = 8, ++(*(ac.index)), (void)0);
}
