/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 09:41:07 by mashad            #+#    #+#             */
/*   Updated: 2021/09/07 17:26:19 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  ** Rotate a - shift up all elements of stack a by 1.
  ** The first element becomes the last one.
*/
void ra(t_stack *a)
{
  int counter;

  printf("ra\n");
  counter = a->top;
  if (is_empty(a) == TRUE)
    return ;
  while (counter >= 1)
  {
    a->int_stack[counter] += a->int_stack[counter - 1];
    a->int_stack[counter - 1] = a->int_stack[counter] - a->int_stack[counter - 1];
    a->int_stack[counter] = a->int_stack[counter] - a->int_stack[counter - 1];
    counter--;
  }
  return ;
}

void rb(t_stack *a)
{
  int counter;

  printf("rb\n");
  counter = a->top;
  if (is_empty(a) == TRUE)
    return ;
  while (counter >= 1)
  {
    a->int_stack[counter] += a->int_stack[counter - 1];
    a->int_stack[counter - 1] = a->int_stack[counter] - a->int_stack[counter - 1];
    a->int_stack[counter] = a->int_stack[counter] - a->int_stack[counter - 1];
    counter--;
  }
  return ;
}

/*
  ** rr : ra and rb at the same time.
*/
void rr(t_stack *a, t_stack *b)
{
  printf("rr\n");
  ra(a);
  rb(b);
  return ;
}
