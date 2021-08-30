/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 09:14:56 by mashad            #+#    #+#             */
/*   Updated: 2021/08/29 09:40:41 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/*
 ** Swap the first 2 elements at the top of stack a. Do nothing if there
 ** is only one or no elements).
*/
void  swap(t_stack *a)
{
  if (a == NULL || a->next == NULL)
    return ;
  while (a->next->next)
    a->next;
  a->n += a->next->n;
  a->next->n = a->n - a->next->n;
  a->n = a->n - a->next->n;
  return ;
}

/*
  ** ss: sa and sb at the same time.
*/
void  ss(t_stack *a, t_stack *b)
{
  swap(a);
  swap(b);
  return ;
}
