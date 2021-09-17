/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:49:15 by mashad            #+#    #+#             */
/*   Updated: 2021/09/17 14:59:21 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Print status function
** its return value depend on the file discriptor
** STDERR means returning an ERROR else it's GOOD
*/
int		print_status(int fd, char *string)
{
	ft_putstr_fd(string, fd);
	if (fd == STDERR)
		return (ERROR);
	return (GOOD);
}

/*
** Dynamically allocate and fill numbers
** from arguments array then return its adress
** in case of an error a NULL is returned
** else a number stack is returned
*/
t_stack	*fill_stack(int length, char **int_array)
{
	t_stack *a;
	int			counter;

	a = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (a == NULL)
		return (NULL);
	a->int_stack = (int *)malloc(sizeof(int) * length - 1);
	if (a->int_stack == NULL)
		return (NULL);
	counter = 0;
	while (--length > 0)
		a->int_stack[counter++] = (int)ft_atoi(int_array[length]);
	a->stack_size = counter;
	a->top = counter - 1;
	return (a);
}

/*
** Allocate and fill stack B
** same size as A
*/
t_stack 	*init_stack(t_stack *a)
{
	t_stack *b;

	b = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (b == NULL)
		return (NULL);
	b->int_stack = (int *)malloc(sizeof(int) * a->stack_size);
	if (b->int_stack == NULL)
	{
		free(b);
		b = NULL;
		return (NULL);
	}
	b->top = -1;
	b->stack_size = a->stack_size;
	return (b);
}
/*
** Choose the right sorting methode
** Based on size of stac A
*/
int 	sorting_stack(t_stack *stack_a)
{
	t_stack *b;

	if (is_sorted(stack_a) == TRUE)
		return (print_status(STDOUT, "OK\n"));
	b = init_stack(stack_a);
	if (b == NULL)
		return (ERROR);
	if (stack_a->stack_size <= 3)
		small_size_sort(stack_a);
	else if (stack_a->stack_size > 10)
		fat_size_sort(stack_a, b);
	else
		big_size_sort(stack_a, b);
	return (GOOD);
}
/*
** Main Function:
** 	Checking arguments error management
** 	Filling the arguments into stack a
** 	Sort the stack a using b stack
*/
int		main(int argc, char **argv)
{
	t_stack	*stack_a;
	int i;

	i = 0;
	if (argc <= 1)
		return (GOOD);
	if (is_valid_arg(argc, argv) != GOOD)
		return (print_status(STDERR, "Error\n"));
	stack_a = fill_stack(argc, argv);
	if (stack_a == NULL)
		return (print_status(STDERR, "Error\n"));
	if (sorting_stack(stack_a) != GOOD)
		return (print_status(STDERR, "Error\n"));
	return (0);
}
