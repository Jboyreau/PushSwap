/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_action.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:17:48 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/27 23:32:40 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	ft_pb(t_lst **sa, t_lst **sb, t_stack *l)
{
	t_lst	*save;

	if (*sb == 0)
	{
		*sb = (*l).la;
		(*(*(*l).la).prev).next = 0;
		(*l).la = (*(*l).la).prev;
		(*l).lb = *sb;
		return ((*(*l).lb).next = 0, (*(*l).lb).prev = 0, 0);
	}
	if (*sa == (*l).la)
	{
		(*(*l).lb).next = (*l).la;
		(*(*l).la).prev = (*l).lb;
		return ((*l).lb = (*l).la, (*l).la = 0, *sa = 0, 0);
	}
	save = (*(*l).la).prev;
	(*(*l).lb).next = (*l).la;
	(*(*l).la).prev = (*l).lb;
	(*save).next = 0;
	return ((*l).lb = (*l).la, (*l).la = save, 0);
}

char	ft_pa(t_lst **sa, t_lst **sb, t_stack *l)
{
	t_lst	*save;

	if (*sa == 0)
	{
		*sa = (*l).lb;
		(*(*(*l).lb).prev).next = 0;
		(*l).lb = (*(*l).lb).prev;
		(*l).la = *sa;
		return ((*(*l).la).next = 0, (*(*l).la).prev = 0, 0);
	}
	if (*sb == (*l).lb)
	{
		(*(*l).la).next = (*l).lb;
		(*(*l).lb).prev = (*l).la;
		return ((*l).la = (*l).lb, (*l).lb = 0, *sb = 0, 0);
	}
	save = (*(*l).lb).prev;
	(*(*l).la).next = (*l).lb;
	(*(*l).lb).prev = (*l).la;
	(*save).next = 0;
	return ((*l).la = (*l).lb, (*l).lb = save, 0);
}

char	ft_s(t_lst **s, t_stack *l, char mode)
{
	t_lst	*save;

	if (*s == (*l).la || *s == (*l).lb || *s == 0)
		return (0);
	if (mode == 'a')
	{
		if (*s == (*(*l).la).prev)
			*s = (*l).la;
		save = (*(*l).la).prev;
		(*(*l).la).next = save;
		(*(*l).la).prev = (*save).prev;
		if ((*save).prev)
			(*(*save).prev).next = (*l).la;
		return ((*save).next = 0, (*save).prev = (*l).la, (*l).la = save, 0);
	}
	if (*s == (*(*l).lb).prev)
		*s = (*l).lb;
	save = (*(*l).lb).prev;
	(*(*l).lb).next = save;
	(*(*l).lb).prev = (*save).prev;
	if ((*save).prev)
		(*(*save).prev).next = (*l).lb;
	return ((*save).next = 0, (*save).prev = (*l).lb, (*l).lb = save, 0);
}

char	ft_r(t_lst **s, t_stack *l, char mode)
{
	t_lst	*save;

	if (*s == (*l).la || *s == (*l).lb || *s == 0)
		return (0);
	if (mode == 'a')
	{
		(*(*l).la).next = *s;
		save = (*(*l).la).prev;
		(*save).next = 0;
		(*(*l).la).prev = 0;
		(**s).prev = (*l).la;
		*s = (*l).la;
		(*l).la = save;
		return (0);
	}
	(*(*l).lb).next = *s;
	save = (*(*l).lb).prev;
	(*save).next = 0;
	(*(*l).lb).prev = 0;
	(**s).prev = (*l).lb;
	*s = (*l).lb;
	(*l).lb = save;
	return (0);
}

char	ft_revr(t_lst **s, t_stack *l, char mode)
{
	t_lst	*save;

	if (*s == (*l).la || *s == (*l).lb || *s == 0)
		return (0);
	if (mode == 'a')
	{
		(*(*l).la).next = *s;
		(**s).prev = (*l).la;
		save = (**s).next;
		(*save).prev = 0;
		(**s).next = 0;
		(*l).la = *s;
		*s = save;
		return (0);
	}
	(*(*l).lb).next = *s;
	(**s).prev = (*l).lb;
	save = (**s).next;
	(*save).prev = 0;
	(**s).next = 0;
	(*l).lb = *s;
	*s = save;
	return (0);
}
