/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 09:55:55 by mashad            #+#    #+#             */
/*   Updated: 2021/09/03 14:25:29 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_empty(t_stack *a)
{
  if (a->top == -1)
    return (TRUE);
  return (FALSE);
}

int pop(t_stack *a)
{
  int number;

  number = a->int_stack[a->top];
  a->top--;
  return (number);
}

int is_sorted(t_stack *a)
{
  int counter;

  counter = 0;
  while (counter < a->top)
  {
    if (a->int_stack[counter] < a->int_stack[counter + 1])
      return (FALSE);
    counter++;
  }
  return (TRUE);
}

int top_element(t_stack *a)
{
  return (a->int_stack[a->top]);
}
