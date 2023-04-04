# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 20:13:40 by gpecci            #+#    #+#              #
#    Updated: 2023/04/04 18:53:47 by gpecci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_BONUS = checker

MAKEFLAGS += --silent

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a
FT_PRINTF_PATH = ft_printf/
FT_PRINTF = $(FT_PRINTF_PATH)libftprintf.a

P1 = moves/
P2 = sort/
P3 = check/
P4 = get_next_line/
P5 = bonus/

SRCS =	$(P1)push.c \
		$(P1)rotate.c \
		$(P1)swap.c \
		$(P1)together.c \
		$(P2)min_moves.c \
		$(P2)min_moves_utils.c \
		$(P2)comb1.c \
		$(P2)comb2_comb3.c \
		$(P2)comb4.c \
		$(P2)sort_two.c \
		$(P2)sort_three.c \
		$(P2)sort_five.c \
		$(P2)sort_big.c \
		$(P3)check.c \
		$(P3)check_utils.c \
		init.c \
		push_swap.c \

SRCS_BONUS =	$(P1)push.c \
				$(P1)rotate.c \
				$(P1)swap.c \
				$(P1)together.c \
				$(P2)min_moves.c \
				$(P2)min_moves_utils.c \
				$(P2)comb1.c \
				$(P2)comb2_comb3.c \
				$(P2)comb4.c \
				$(P2)sort_two.c \
				$(P2)sort_three.c \
				$(P2)sort_five.c \
				$(P2)sort_big.c \
				$(P3)check.c \
				$(P3)check_utils.c \
				$(P4)get_next_line.c \
				$(P4)get_next_line_utils.c \
				init.c \
				$(P5)checker.c \
				$(P5)checker_utils.c \

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS) $(LIBFT) $(FT_PRINTF)
			$(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "\033[32mCompiled OK!\033[0m"

$(FT_PRINTF):
				make -C $(FT_PRINTF_PATH)

$(LIBFT):
			make -C $(LIBFT_PATH)


all : $(NAME)

bonus:	$(OBJS_BONUS) $(LIBFT) $(FT_PRINTF)
		$(CC) $(OBJS_BONUS) $(LIBFT) $(FT_PRINTF) -o $(NAME_BONUS)
	@echo "\033[32mBonus Compiled OK!\033[0m"

clean:
		${RM} ${OBJS}
		${RM} ${OBJS_BONUS}
		make clean -C ${LIBFT_PATH}
		make clean -C ${FT_PRINTF_PATH}
	@echo "\033[33mclean OK!\033[0m"

fclean:		clean
				rm -f $(NAME)
				rm -f $(NAME_BONUS)
				rm -f ${LIBFT}
				rm -f ${FT_PRINTF}
				@echo "\033[33mfclean OK!\033[0m"

re:				fclean all
