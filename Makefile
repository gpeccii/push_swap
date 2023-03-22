# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpecci <gpecci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 20:13:40 by gpecci            #+#    #+#              #
#    Updated: 2023/03/22 20:13:41 by gpecci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a
FT_PRINTF_PATH = ft_printf/
FT_PRINTF = $(FT_PRINTF_PATH)libftprintf.a

P1 = moves/

SRCS =	$(P1)push.c \
		$(P1)rotate.c \
		$(P1)swap.c \
		$(P1)together.c \
		check.c \
		lis.c \
		sort.c \
		push_swap.c \

OBJS = ${SRCS:.c=.o}

CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS) $(LIBFT) $(FT_PRINTF)
			$(CC) $(OBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(FT_PRINTF):
				make -C $(FT_PRINTF_PATH)

$(LIBFT):
			make -C $(LIBFT_PATH)

all : $(NAME)

clean:
		${RM} ${OBJS}
		make clean -C ${LIBFT_PATH}
		make clean -C ${FT_PRINTF_PATH}

fclean:		clean
				rm -f $(NAME)
				rm -f ${LIBFT}
				rm -f ${FT_PRINTF}

re:				fclean all
