/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:43:03 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/29 11:34:48 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SIZE 5
# define SIZE_SUB_THREE 3
# define LAST_INDEX 4

typedef struct s_lst
{
	char			pivot;
	int				data;
	struct s_lst	*next;
	struct s_lst	*prev;
}					t_lst;

typedef struct s_actions
{
	unsigned int	*index;
	char			*actions;
}					t_actions;

typedef struct s_stack
{
	t_actions			ac;
	t_lst				*alloc;
	t_lst				*fa;
	t_lst				*fb;
	t_lst				*la;
	t_lst				*lb;
	long long int		*tab;
	char				*p_tab;
	unsigned int		size_tab;
	unsigned int		ip;
	unsigned int		size_stack;
	unsigned int		size_block;
	unsigned char		n;
}						t_stack;

int				ft_str_count(char **argv, int argc, long long int **tab);
int				ft_word_count(char *s, char *save, long long int **tab, int i);
char			ft_check_double(long long int *tab, int size);
char			ft_pa(t_lst **sa, t_lst **sb, t_stack *l);
char			ft_pb(t_lst **sa, t_lst **sb, t_stack *l);
char			ft_s(t_lst **s, t_stack *l, char mode);
char			ft_r(t_lst **s, t_stack *l, char mode);
char			ft_revr(t_lst **s, t_stack *l, char mode);
void			ft_fill_actions(char data, t_actions ac);
void			ft_pa_print(t_lst **sa, t_lst **sb, t_stack *l, t_actions ac);
void			ft_pb_print(t_lst **sa, t_lst **sb, t_stack *l, t_actions ac);
void			ft_s_print(t_lst **s, t_stack *l, char mode, t_actions ac);
void			ft_r_print(t_lst **s, t_stack *l, char mode, t_actions ac);
void			ft_revr_print(t_lst **s, t_stack *l, char mode, t_actions ac);
void			ft_show(t_actions ac);
char			ft_quick_sort(t_stack *s);
int				ft_size_block(char *p_tab, int start);
void			ft_push_b(t_stack *s, int i);
void			ft_push_a(t_stack *s);
void			ft_p_tab_init(char *p_tab, int size);
char			ft_costr_b(t_lst *l, t_lst *f, int data);
char			ft_costr_a(t_lst *l, t_lst *f, int data);
char			ft_tofind_b(t_lst *l, int data);
char			ft_tofind_a(t_lst *l, int data);
int				ft_lstlen(t_lst *l);
char			ft_is_presort(char *p_tab, int size);
void			ft_turbo_insertion(t_stack *s, int i);
void			ft_brut_force(t_stack *s, int i, char j);
char			ft_brut_force_to_a(t_stack *s, int i, char j, char n);
char			ft_issort0(t_lst *fa, t_stack *s);
char			ft_apply0(t_lst **fa, t_stack *s, int data);
char			ft_test0(t_lst *fa, t_stack *s, char *tab);
void			ft_init02(t_lst *stacks, t_stack *s, unsigned int i);
void			ft_init0(char *tab, t_lst *stacks, t_stack *s, int len);
char			ft_issort(t_lst *fa, t_stack *s);
char			ft_apply(t_lst **fb, t_stack *s, int data);
char			ft_test(t_lst *fb, t_stack *s, char *tab);
void			ft_init2(t_lst *stacks, t_stack *s, t_lst *lb_cpy, int i);
void			ft_init(char *tab, t_lst *stacks, t_stack *s, int len);
long long int	ft_atoi_s(char *s, char sign, long long int sum);
#endif
