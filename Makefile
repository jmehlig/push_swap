# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 12:26:53 by jmehlig           #+#    #+#              #
#    Updated: 2022/01/13 20:14:19 by jmehlig          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

C_FLAGS=-Wall -Wextra -Werror

NAME_MAIN=push_swap

LIBS=libft/libft.a

SRC_DIR=./
SRC_LIST_MAIN= push_swap.c
SRC_LIST=atoi_ex.c\
	ops1.c\
	do_ops.c\
	sort_three.c\
	quicksort.c\
	push_sort.c\
	swap_b.c\
	half.c\
	halfb.c\
	stackb.c\
	push_begin.c\
	utils.c\

SRC=$(addprefix $(SRC_DIR), $(SRC_LIST))
SRC_MAIN= $(addprefix $(SRC_DIR), $(SRC_LIST_MAIN))

all: $(NAME_MAIN)

$(NAME_MAIN): $(SRC) $(SRC_MAIN)
	make -C libft
	$(CC) $(C_FLAGS) $^ $(LIBS) -o $@

$(OBJ_LIST): $(SRC_LIST)

clean:
	make -C libft clean

fclean:
	make -C libft fclean
	rm -f $(NAME_MAIN) $(NAME_BONUS)

re:
	make fclean
	make $(NAME)
