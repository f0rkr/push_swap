/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashad <mashad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 11:50:04 by mashad            #+#    #+#             */
/*   Updated: 2021/08/31 08:59:28 by mashad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# define STDIN	0
# define STDOUT	1
# define STDERR	2
# define ERROR	-1
# define GOOD	1
# define OVERFLOW -1

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

int	is_valid_arg(int len, char **int_arry);

#endif
