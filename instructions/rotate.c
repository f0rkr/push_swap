/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 09:41:07 by mashad            #+#    #+#             */
/*   Updated: 2021/08/29 19:56:07 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  ** Rotate a - shift up all elements of stack a by 1.
  ** The first element becomes the last one.
*/
void rotate(t_stack a)
{
  t_stack a_rotated;
  
  if (a == NULL || a->next == NULL)
    return ;
  while ()

}

/*
  ** rr : ra and rb at the same time.
*/
void rr(t_stack *a, t_stack *b)
{
  rotate(a);
  rotate(b);
  return ;
}
