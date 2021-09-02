/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 09:26:56 by mashad            #+#    #+#             */
/*   Updated: 2021/08/29 09:30:05 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
  ** Get last element of the stack
*/

t_stack *ft_lstlast(t_stack a)
{
  while (a->next)
    a = a->next;
  return (a);
}
