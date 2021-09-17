/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:35:17 by mashad            #+#    #+#             */
/*   Updated: 2021/09/07 16:47:04 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Get how many falses elements
** we get with the chosen markup_head
*/
int   get_number_false_elements(t_stack *a, int *elements_status)
{
	int false_elements;
  int i;

  i = 0;
	false_elements = 0;
  while (i < a->stack_size * 2)
  {
    if (elements_status[i + 1] == 0)
    	false_elements++;
    i+=2;
  }
  return (false_elements);
}

/*
** Returns an array of true and falses elements
*/
int   *get_elements_status(t_stack *a, int markup_head)
{
  int *falses;
	int flag;
  int i;
  int j;

  j = 0;
	flag = 0;
  i = markup_head;
  falses = (int *)malloc(sizeof(int) * a->stack_size * 2);
  if (!falses)
    return (NULL);
  ft_memset(falses, 0, a->stack_size * 2);
  falses[j++] = a->int_stack[i];
  falses[j++] = 1;
  while (i > 0)
  {
		falses[j++] = a->int_stack[i - 1];
    if ( a->int_stack[i] < a->int_stack[i - 1])
      falses[j++] = 1;
		else
		{
			falses[j++] = 0;
  		flag = 1;
		}
		i--;
	}
	flag = 0;
  i = markup_head;
  while (i < a->stack_size - 1)
  {
		falses[j++] = a->int_stack[i + 1];
    if ( a->int_stack[i] < a->int_stack[i + 1])
      falses[j++] = 1;
    else
		{
			falses[j++] = 0;
  		flag = 1;
		}
		i++;
  }
  return (falses);
}

/*
** Calculate the best markup head
** and return it
*/
int   get_markup_head(t_stack *a)
{
	int *elements_status;
	int false_elements;
	int markup_head;
	int *tmp;
	int i;

	i = 0;
	elements_status = get_elements_status(a, 0);
	false_elements = get_number_false_elements(a, elements_status);
	while (i < a->stack_size)
	{
		tmp = get_elements_status(a, i);
		if (false_elements > get_number_false_elements(a, tmp))
		{
			markup_head = i;
			false_elements = get_number_false_elements(a, tmp);
		}
		else if (false_elements == get_number_false_elements(a, tmp) && markup_head > i)
		{
			markup_head = i;
			false_elements = get_number_false_elements(a, tmp);
		}
		i++;
	}
	return (markup_head);
}

/*
** Search for element in elements_status
** Return it's status
** else an error is returned
*/
int   is_element_false(t_stack *a, int *elements_status, int index)
{
  int i;

  i = 0;
  while (i < a->stack_size * 2)
  {
    if (elements_status[i] == index)
      return (elements_status[i + 1]);
    i+=2;
  }
  return (ERROR);
}

int			is_sa_needed(t_stack *a, int *elements_status, int false_elements)
{
	int markup_head;
	int *indexes;
	int falses;
	int tmp;

	tmp = a->int_stack[a->top];
	a->int_stack[a->top] = a->int_stack[a->top - 1];
	a->int_stack[a->top - 1] = tmp;
	indexes = get_indexes(a);
	markup_head = get_markup_head(a);
	falses = get_number_false_elements(a, elements_status);
	tmp = a->int_stack[a->top];
	a->int_stack[a->top] = a->int_stack[a->top - 1];
	a->int_stack[a->top - 1] = tmp;
	free(indexes);
	indexes = NULL;
	if (falses < false_elements)
		return (TRUE);
	return (FALSE);
}
