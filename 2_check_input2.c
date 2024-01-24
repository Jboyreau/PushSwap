/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_check_input2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jboyreau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:21:51 by jboyreau          #+#    #+#             */
/*   Updated: 2023/01/29 11:30:33 by jboyreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#define M 2147483647
#define M_ 2147483648

long long int	ft_atoi_s(char *s, char sign, long long int sum)
{
	if (*s == '-')
		sign *= -1;
	if (*s == '+' || *s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		if (((sum * 10 + *s - 48) > M && sign > -1)
			|| sum * 10 + *s - 48 > M_)
			return ((size_t)M + 1);
		sum = sum * 10 + *(s++) - 48;
	}
	return (sum * sign);
}
