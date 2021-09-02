/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:49:15 by mashad            #+#    #+#             */
/*   Updated: 2021/08/31 08:46:08 by mashad           ###   ########.fr       */
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
	int			i;

	i = 0;
	a = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (a == NULL)
		return (NULL);
	a->int_stack = (int *)malloc(sizeof(int) * length - 1);
	if (a->int_stack == NULL)
		return (NULL);
	a->stack_size = length - 1;
	while (i < a->stack_size)
	{
		a->int_stack[i] = ft_atoi(int_array[i + 1]);
		i++;
	}
	return (a);
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
	// t_stack	*stack_b;

	i = 0;
	if (argc <= 1)
		return (GOOD);
	if (is_valid_arg(argc, argv) != GOOD)
		return (print_status(STDERR, "Error\n"));
	stack_a = fill_stack(argc, argv);
	if (stack_a == NULL)
		return (print_status(STDERR, "Error\n"));
	while (i < stack_a->stack_size)
		printf("%d ", stack_a->int_stack[i++]);
	// if (sorting_stack(a) != GOOD)
	// 	return (print_status(STDERR, "Error\n"));
	return (0);
}
