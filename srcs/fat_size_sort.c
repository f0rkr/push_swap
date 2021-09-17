/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_size_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 16:20:00 by mashad            #+#    #+#             */
/*   Updated: 2021/09/17 15:39:53 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Get the smallest number of stack
** Excluding last small numbers
*/
int		get_smallest_position(t_stack *a, int *indexes)
{
	int i;
	int position;

	i = 0;
	position = get_biggest(a);
	while (i < a->stack_size)
	{
		if (a->int_stack[position] > a->int_stack[i] && indexes[i] == -1)
			position = i;
    i++;
	}
	return (position);
}

/*
** Indexing a stack from smallest to biggest
*/
int   *get_indexes(t_stack *a)
{
  int i;
  int index;
  int *indexes;

  i = 0;
  index = 0;
  indexes = (int *)malloc(sizeof(int) * a->stack_size);
  ft_memset(indexes, -1, a->stack_size);
  while (i < a->stack_size)
  {
    indexes[get_smallest_position(a, indexes)] = index++;
    i++;
  }
  return (indexes);
}


/*
** Sorting algorith for big numbers >5
** Using indexing and markups
*/
int   fat_size_sort(t_stack *a, t_stack *b)
{
	int stor_number;
	int i;
	int j;

	j = 0;
	i = 0;
	while (!is_sorted(a))
	{
		i = 0;
		while (i < a->top)
		{
			stor_number = a->int_stack[a->top];
			if ((stor_number >> j) & 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		j++;
	}
	while (!is_empty(b))
		pa(b, a);
	return (GOOD);
}
