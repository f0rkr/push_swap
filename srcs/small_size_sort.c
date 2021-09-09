/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_size_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:00:42 by mashad            #+#    #+#             */
/*   Updated: 2021/09/04 13:27:09 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int   is_smallest(int number, t_stack *a)
{
  int i;

  i = 0;
  while (i <= a->top)
  {
    if (number > a->int_stack[i])
      return (FALSE);
    i++;
  }
  return (TRUE);
}

/*
** Check if the number
** is the biggest number in the stack
** and return True or False
*/
int   get_biggest(t_stack *a)
{
  int i;
  int pos;
  i = 0;

  pos = a->top;
  while (i <= a->top)
  {
    if (a->int_stack[pos] < a->int_stack[i])
      pos = i;
    i++;
  }
  return (pos);
}

void  put_biggest_last(t_stack *a)
{
  int b_position;

  b_position = get_biggest(a);
  if (b_position == a->top)
    ra(a);
  else if (b_position == a->top - 1)
    rra(a);
  return ;
}
/*
  ** Sorting small stacks
*/
int   small_size_sort(t_stack *a)
{
  int b_position;

  b_position = get_biggest(a);
  put_biggest_last(a);
  if (!is_sorted(a))
    sa(a);
  return (GOOD);
}
