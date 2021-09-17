/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 09:21:23 by mashad            #+#    #+#             */
/*   Updated: 2021/09/04 08:18:14 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  ** Take the first element at the top of b and put it at the top of a. Do
  ** nothing if b is empty
*/
void  pa(t_stack *a, t_stack *b)
{
  printf("pa\n");
  if (b->top == b->stack_size - 1)
    return ;
  b->top++;
  b->int_stack[b->top] = a->int_stack[a->top];
  a->top--;
  return ;
}

void  pb(t_stack *b, t_stack *a)
{
  printf("pb\n");
  if (a->top == a->stack_size - 1)
    return ;
  a->top++;
  a->int_stack[a->top] = b->int_stack[b->top];
  b->top--;
  return ;
}
