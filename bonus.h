/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:37:22 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/29 06:40:34 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H
# include "push_swap.h"

void	ft_apply_bonus(t_stack *s, char action);
char	ft_check_buffer(char *tab);
void	ft_valid_ornot(t_lst *fa, t_lst *fb);
void	ft_pa_safe(t_stack *s);
void	ft_pb_safe(t_stack *s);
void	ft_sa_safe(t_stack *s);
void	ft_sb_safe(t_stack *s);
void	ft_ra_safe(t_stack *s);
void	ft_rb_safe(t_stack *s);
void	ft_rra_safe(t_stack *s);
void	ft_rrb_safe(t_stack *s);
void	ft_ss_safe(t_stack *s);
void	ft_rr_safe(t_stack *s);
void	ft_rrr_safe(t_stack *s);
void	ft_read(char *read, char *tab, char *save, int *n);
void	ft_set(char *tab);
#endif
