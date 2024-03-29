/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:06:09 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/28 09:06:47 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	ft_rrr_safe(t_stack *s)
{
	if ((*s).fb == 0 || (*s).fb == (*s).lb
		|| (*s).fa == 0 || (*s).fa == (*s).la)
		return ;
	ft_rrb_safe(s);
	ft_rra_safe(s);
}
