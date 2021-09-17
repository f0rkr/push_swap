/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 08:34:38 by mashad            #+#    #+#             */
/*   Updated: 2021/09/08 09:09:21 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  rot(t_stack *a)
{
  int counter;

  counter = 0;
  if (is_empty(a) == TRUE)
    return ;
  while (counter < a->top)
  {
    a->int_stack[counter] += a->int_stack[counter + 1];
    a->int_stack[counter + 1] = a->int_stack[counter] - a->int_stack[counter + 1];
    a->int_stack[counter] = a->int_stack[counter] - a->int_stack[counter + 1];
    counter++;
  }
  return ;
}

void  rra(t_stack *a)
{
  printf("rra\n");
  rot(a);
  return ;
}

void  rrb(t_stack *a)
{
  printf("rrb\n");
  rot(a);
  rot(a);
  return ;
}

void  rrr(t_stack *a, t_stack *b)
{
  printf("rrr\n");
  rot(a);
  rot(b);
  return ;
}
