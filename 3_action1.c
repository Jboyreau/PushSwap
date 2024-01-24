/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_action2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 23:22:03 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/27 23:37:55 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap.h"

void	ft_pa_print(t_lst **sa, t_lst **sb, t_stack *l, t_actions ac)
{
	ft_pa(sa, sb, l);
	ft_fill_actions(1, ac);
}

void	ft_pb_print(t_lst **sa, t_lst **sb, t_stack *l, t_actions ac)
{
	ft_pb(sa, sb, l);
	ft_fill_actions(2, ac);
}

void	ft_s_print(t_lst **s, t_stack *l, char mode, t_actions ac)
{
	ft_s(s, l, mode);
	if (mode == 'a')
		return (ft_fill_actions(3, ac));
	ft_fill_actions(4, ac);
}

void	ft_r_print(t_lst **s, t_stack *l, char mode, t_actions ac)
{
	ft_r(s, l, mode);
	if (mode == 'a')
		return (ft_fill_actions(5, ac));
	ft_fill_actions(6, ac);
}

void	ft_revr_print(t_lst **s, t_stack *l, char mode, t_actions ac)
{
	ft_revr(s, l, mode);
	if (mode == 'a')
		return (ft_fill_actions(7, ac));
	ft_fill_actions(8, ac);
}
