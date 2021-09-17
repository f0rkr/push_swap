/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_size_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 17:00:58 by mashad            #+#    #+#             */
/*   Updated: 2021/09/08 09:14:54 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int   get_smallest(t_stack *a)
{
  int i;
  int pos;

  i = 0;
  pos = 0;
  if (a->top < 1)
    return (a->top);
  while (i <= a->top)
  {
    if (a->int_stack[pos] > a->int_stack[i])
      pos = i;
    i++;
  }
  return (pos);
}

void  push_smallest(t_stack *a, t_stack *b)
{
  int b_position;
  int proximity;

  proximity = (a->top / 2);
  b_position = get_smallest(a);
  if (b_position == a->top - 1)
    sa(a);
  else if (b_position != a->top && b_position >= proximity)
    ra(a);
  else if (b_position != a->top && b_position < proximity)
    rra(a);
  if (!is_sorted(a) && b_position != a->top)
    push_smallest(a, b);
  return ;
}

void  pop_biggest(t_stack *a, t_stack *b)
{
  pa(b, a);
  return ;
}

int   big_size_sort(t_stack *a, t_stack *b)
{
  while (a->top > 2 && !is_sorted(a))
  {
      push_smallest(a, b);
      if (!is_sorted(a))
        pb(a, b);
  }
  if (!is_sorted(a))
    small_size_sort(a);
  while (b->top != -1)
    pop_biggest(a, b);
  return (GOOD);
}
