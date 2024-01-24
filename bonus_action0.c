/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 08:15:58 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/28 09:05:52 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_pa_safe(t_stack *s)
{
	if ((*s).fb == 0)
		return ;
	ft_pa(&(*s).fa, &(*s).fb, s);
}

void	ft_pb_safe(t_stack *s)
{
	if ((*s).fa == 0)
		return ;
	ft_pb(&(*s).fa, &(*s).fb, s);
}

void	ft_sa_safe(t_stack *s)
{
	if ((*s).fa == 0 || (*s).fa == (*s).la)
		return ;
	ft_s(&(*s).fa, s, 'a');
}

void	ft_sb_safe(t_stack *s)
{
	if ((*s).fb == 0 || (*s).fb == (*s).lb)
		return ;
	ft_s(&(*s).fb, s, 'b');
}

void	ft_ra_safe(t_stack *s)
{
	if ((*s).fa == 0 || (*s).fa == (*s).la)
		return ;
	ft_r(&(*s).fa, s, 'a');
}
