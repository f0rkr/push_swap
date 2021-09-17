/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 09:14:56 by mashad            #+#    #+#             */
/*   Updated: 2021/09/03 15:12:29 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/*
 ** Swap the first 2 elements at the top of stack a. Do nothing if there
 ** is only one or no elements).
*/
void  sa(t_stack *a)
{
  int tmp;

  printf("sa\n");
  if (is_empty(a) && a->top < 1)
    return ;
  tmp = a->int_stack[a->top];
  a->int_stack[a->top] = a->int_stack[a->top - 1];
  a->int_stack[a->top - 1] = tmp;
  return ;
}

void  sb(t_stack *a)
{
  int tmp;

  printf("sb\n");
  if (is_empty(a) && a->top < 1)
    return ;
  tmp = a->int_stack[a->top];
  a->int_stack[a->top] = a->int_stack[a->top - 1];
  a->int_stack[a->top - 1] = tmp;
  return ;
}
/*
  ** ss: sa and sb at the same time.
*/
void  ss(t_stack *a, t_stack *b)
{
  printf("ss\n");
  sa(a);
  sb(b);
  return ;
}
