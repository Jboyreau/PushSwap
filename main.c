#include "push_swap.h"

int nb = 0;

void ft_print_sorted_sequence(t_operations *actions, t_array *tab_int)
{
	int i = 0;

	while (i <= (*tab_int).index_actions)
	{
		if (*(actions + i) == PA)
		{
			write(1, "pa\n", 3);
		}
		else if (*(actions + i) == PB)
		{
			write(1, "pb\n", 3);
		}
		else if (*(actions + i) == SA)
		{	
			write(1, "sa\n", 3);
		}
		else if (*(actions + i) == SB)
		{
			write(1, "sb\n", 3);
		}
		else if (*(actions + i) == RA)
		{
			write(1, "ra\n", 3);
		}
		else if (*(actions + i) == RB)
		{
			write(1, "rb\n", 3);
		}
		else if (*(actions + i) == RRA)
		{
			write(1, "rra\n", 4);
		}
		else if (*(actions + i) == RRB)
		{
			write(1, "rrb\n", 4);
		}
		else if (*(actions + i) == RRR)
		{
			write(1, "rrr\n", 4);
		}
		else if (*(actions + i) == RR)
		{
			write(1, "rr\n", 3);
		}
		else if (*(actions + i) == SS)
		{
			write(1, "ss\n", 3);
		}
		++i;
	}
}

void clean_actions(t_operations *actions, int size)
{	
	int i = 0;

	while (i <= size)
	{
		if ((*(actions + i) == RRA && *(actions + i + 1) == RRB) || (*(actions + i) == RRB && *(actions + i + 1) == RRA))
		{
			++nb;
			*(actions + i) = RRR;
			*(actions + i + 1) = END;
		}
		else if ((*(actions + i) == RA && *(actions + i + 1) == RB) || (*(actions + i) == RB && *(actions + i + 1) == RA))
		{
			++nb;
			*(actions + i) = RR;
			*(actions + i + 1) = END;
		}
		else if ((*(actions + i) == SA && *(actions + i + 1) == SB) || (*(actions + i) == SB && *(actions + i + 1) == SA))
		{
			++nb;
			*(actions + i) = SS;
			*(actions + i + 1) = END;
		}
		i += 2;
	}
}

int main(int argc, char **argv)
{
	static t_array tab_int;

	if (argc == 2)
	{
		if (!fill_tab_str(argc, argv[1], &tab_int))
			return (write(1, "malloc failed\n", 14), 1);
	}
	else
	{
		if (!fill_tab_argv(argc, argv, &tab_int))
			return (write(1, "malloc failed\n", 14), 1);
	}
	if (tab_int.overflow == 1)
		return (free(tab_int.tab), write(1, "overflow\n", 9), 1);
	ft_init_list(tab_int.first_a, tab_int.size);
	if (tab_int.size == 1 || ft_unsorted(tab_int.first_a) == 0)
		return (free(tab_int.tab), 0);
	ft_sort_int_array(tab_int.tab, tab_int.size);

	//puts("\tstack a -----------------------");
	//debug_printlist(tab_int.first_a);

	if (!init_brute_force((tab_int).first_a, &(tab_int)))
	{
		ft_print_sorted_sequence(tab_int.actions, &tab_int);
		return (free(tab_int.tab), 0);
	}
	sorting_algo((&(tab_int)));
//	puts("stack b -----------------------");
//	debug_printlist(tab_int.first_b);
	clean_actions(tab_int.actions, tab_int.index_actions);
	ft_print_sorted_sequence(tab_int.actions, &tab_int);
	printf("%d\n", nb);
	return (free(tab_int.tab), 0);
}

