# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 14:47:42 by jboyreau          #+#    #+#              #
#    Updated: 2023/01/29 11:37:06 by jboyreau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

NAME_BONUS=checker

OBJ=1_push_swap.o \
	2_check_input.o 2_check_input2.o\
	3_action0.o 3_action1.o 3_action2.o \
	4_sort_brut_force_pure0.o 4_sort_brut_force_pure1.o \
	5_quick_sort.o 5_quick_sort_utils.o 5_quick_sort_utils2.o \
	6_sort_brut_force_to_a.o 6_sort_brut_force_to_a2.o 6_sort_turbo_insertion.o \
	7_show.o

OBJ_BONUS=bonus_checker.o bonus_checker_utils.o bonus_action0.o bonus_action1.o bonus_action2.o\
		2_check_input.o 2_check_input2.o 3_action0.o

$(NAME): $(OBJ)
	cc -g3 -Wall -Wextra -Werror $(OBJ) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS)
	cc -g3 -Wall -Wextra -Werror $(OBJ_BONUS) -o $(NAME_BONUS)

1_push_swap.o: 1_push_swap.c push_swap.h
	cc -Wall -Wextra -Werror -c $<
2_check_input.o: 2_check_input.c push_swap.h
	cc -Wall -Wextra -Werror -c $<
2_check_input2.o: 2_check_input2.c push_swap.h
	cc -Wall -Wextra -Werror -c $<
3_action0.o: 3_action0.c push_swap.h
	cc -Wall -Wextra -Werror -c $<
3_action1.o: 3_action1.c push_swap.h
	cc -Wall -Wextra -Werror -c $<
3_action2.o: 3_action2.c push_swap.h
	cc -Wall -Wextra -Werror -c $<
4_sort_brut_force_pure0.o: 4_sort_brut_force_pure0.c push_swap.h
	cc -Wall -Wextra -Werror -c $<
4_sort_brut_force_5_pure1.o: 4_sort_brut_force_pure1.c push_swap.h
	cc -Wall -Wextra -Werror -c $<
5_quick_sort.o: 5_quick_sort.c push_swap.h
	cc -Wall -Wextra -Werror -c $<
5_quick_sort_utils.o:5_quick_sort_utils.c push_swap.h
	cc -Wall -Wextra -Werror -c $<
5_quick_sort_utils2.o: 5_quick_sort_utils2.c push_swap.h
	cc -Wall -Wextra -Werror -c $<
6_sort_brut_force_to_a.o: 6_sort_brut_force_to_a.c push_swap.h
	cc -Wall -Wextra -Werror -c $<
6_sort_brut_force_to_a2.o: 6_sort_brut_force_to_a2.c push_swap.h
	cc -Wall -Wextra -Werror -c $<
6_sort_turbo_insertion.o: 6_sort_turbo_insertion.c push_swap.h
	cc -Wall -Wextra -Werror -c $<
7_show.o: 7_show.c push_swap.h
	cc -Wall -Wextra -Werror -c $<
bonus_checker.o: bonus_checker.c push_swap.h bonus.h
	cc -Wall -Wextra -Werror -c $<
bonus_checker_utils.o: bonus_checker_utils.c push_swap.h bonus.h
	cc -Wall -Wextra -Werror -c $<
bonus_action0.o: bonus_action0.c push_swap.h bonus.h
	cc -Wall -Wextra -Werror -c $<
bonus_action1.o: bonus_action1.c push_swap.h bonus.h
	cc -Wall -Wextra -Werror -c $<
bonus_action2.o: bonus_action2.c push_swap.h bonus.h
	cc -Wall -Wextra -Werror -c $<

all: $(NAME)

bonus: $(NAME_BONUS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re
