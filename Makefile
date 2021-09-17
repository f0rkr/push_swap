# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mashad <mashad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/31 11:40:29 by mashad            #+#    #+#              #
#    Updated: 2021/09/06 07:59:57 by mashad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap
BONUS_NAME=checker
CC=gcc
FLAGS=-Wall -Werror -Wextra
SRCS=srcs/push_swap.c srcs/push_swap_utils.c srcs/fat_size_sort.c srcs/stack_operation.c srcs/big_size_sort.c  srcs/small_size_sort.c srcs/sorting_tools.c instructions/push.c instructions/swap.c instructions/rotate.c instructions/reverse_rotate.c
BONUS_SRCS=bonus_srcs/checker.c
INCLUDES=includes/
LIB_PATH=libft/
LIB_NAME=libft/libft.a
DEBUG= -g
SANITIZE=-fsanitize=address
all: $(NAME)

$(NAME): $(SRCS)
	make -C $(LIB_PATH)
	make -C $(LIB_PATH) clean
	$(CC) $(FLAGS) -I $(INCLUDES) $(SANITIZE) -I $(LIB_PATH) $(SRCS) $(LIB_NAME) -o $(NAME)

$(BONUS_NAME) : $(BONUS_SRCS)
	make -C $(LIB_PATH)
	make -C $(LIB_PATH) clean
	$(CC) $(FLAGS) -I $(INCLUDES) -I $(LIB_PATH) $(BONUS_SRCS) $(LIB_NAME) -o $(BONUS_NAME)
libft:
	make -C $(LIB_PATH)
	make -C $(LIB_PATH) clean
clean:
	make -C $(LIB_PATH) clean

fclean : clean
	make -C $(LIB_PATH) fclean
	rm -rf $(NAME) $(BONUS_NAME)

re : fclean all
