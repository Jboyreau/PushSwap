/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 08:20:16 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/28 09:07:18 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_rb_safe(t_stack *s)
{
	if ((*s).fb == 0 || (*s).fb == (*s).lb)
		return ;
	ft_r(&(*s).fb, s, 'b');
}

void	ft_rra_safe(t_stack *s)
{
	if ((*s).fa == 0 || (*s).fa == (*s).la)
		return ;
	ft_revr(&(*s).fa, s, 'a');
}

void	ft_rrb_safe(t_stack *s)
{
	if ((*s).fb == 0 || (*s).fb == (*s).lb)
		return ;
	ft_revr(&(*s).fb, s, 'b');
}

void	ft_ss_safe(t_stack *s)
{
	if ((*s).fb == 0 || (*s).fb == (*s).lb
		|| (*s).fa == 0 || (*s).fa == (*s).la)
		return ;
	ft_sb_safe(s);
	ft_sa_safe(s);
}

void	ft_rr_safe(t_stack *s)
{
	if ((*s).fb == 0 || (*s).fb == (*s).lb
		|| (*s).fa == 0 || (*s).fa == (*s).la)
		return ;
	ft_rb_safe(s);
	ft_ra_safe(s);
}
