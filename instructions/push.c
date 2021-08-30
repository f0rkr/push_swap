/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 09:21:23 by mashad            #+#    #+#             */
/*   Updated: 2021/08/29 09:49:26 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  ** Take the first element at the top of b and put it at the top of a. Do
  ** nothing if b is empty
*/
void  push(t_stack *a, t_stack *b)
{
  t_stack *b_last;
  t_stack *bb_last;

  if (b == NULL)
    return ;
  a = ft_lstlast(a);
  b_last = ft_lstlast(b);
  bb_last = b;
  while (bb_last->next->next)
    bb_last = bb_last->next;
  a = (t_stack *)malloc(sizeof(t_stack) * 1);
  if (a == NULL)
    return ;
  a->n = b_last->n;
  a->next = NULL;
  free(b_last);
  bb_last->next = NULL;
  return ;
}
