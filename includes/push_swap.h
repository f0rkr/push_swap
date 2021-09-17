/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:50:04 by mashad            #+#    #+#             */
/*   Updated: 2021/09/07 16:34:00 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# define TRUE		1
# define FALSE 	0
# define STDIN	0
# define STDOUT	1
# define STDERR	2
# define ERROR	-1
# define GOOD	1
# define OVERFLOW -2147483649

# include <unistd.h>
# include <stdlib.h>
# include <libft.h>
# include <stdio.h>
# include <string.h>

/*
** DECLARATION OF STACK
*/
typedef struct 	s_stack
{
	int 	*int_stack;
	int 	stack_size;
	int 	top;
}				t_stack;

int		is_valid_arg(int len, char **int_arry);
int		is_empty(t_stack *a);
int		is_sorted(t_stack *a);
int		top_element(t_stack *a);
int		pop(t_stack *a);
void 	pa(t_stack *a, t_stack *b);
void 	pb(t_stack *a, t_stack *b);
void 	ra(t_stack *a);
void 	rb(t_stack *a);
void 	rr(t_stack *a, t_stack *b);
void  sa(t_stack *a);
void  sb(t_stack *a);
void  ss(t_stack *a, t_stack *b);
int   small_size_sort(t_stack *a);
int   big_size_sort(t_stack *a, t_stack *b);
int   fat_size_sort(t_stack *a, t_stack *b);
void  rra(t_stack *a);
void  rrb(t_stack *a);
void  rrr(t_stack *a, t_stack *b);
int   get_biggest(t_stack *a);
int   get_smallest(t_stack *a);
int   get_markup_head(t_stack *a);
int   get_number_false_elements(t_stack *a, int *elements_status);
int   *get_elements_status(t_stack *a, int markup_head);
int   is_element_false(t_stack *a, int *elements_status, int index);
int			is_sa_needed(t_stack *a, int *elements_status, int false_elements);
int   *get_indexes(t_stack *a);
#endif
