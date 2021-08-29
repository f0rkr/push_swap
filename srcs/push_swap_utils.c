/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 12:19:45 by mashad            #+#    #+#             */
/*   Updated: 2021/08/29 08:32:16 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_duplicate(int len, char **int_array)
{
	int	s_count;
	int	j_count;

	s_count = 1;
	while (s_count < len)
	{
		j_count = 1;
		while (j_count < len)
		{
			if (s_count != j_count && ft_strncmp(int_array[s_count], int_array[j_count], ft_strlen(int_array[s_count])) == 0)
				return (ERROR);
			j_count++;
		}
		s_count++;
	}
	return (GOOD);
}

int			check_max_int(int len, char **int_array)
{
	int	s_count;

	s_count = 1;
	while (s_count < len)
	{
		if (ft_atoi(int_array[s_count]) == OVERFLOW)
			return (ERROR);
		s_count++;
	}
	return (GOOD);
}

extern int	is_valid_arg(int len, char **int_array)
{
	int	s_count;

	s_count = 1;
	if (check_duplicate(len, int_array) != GOOD)
		return (ERROR);
	if (check_max_int(len, int_array) != GOOD)
		return (ERROR);
	return (GOOD);
}
