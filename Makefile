# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lejimene <lejimene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 18:18:05 by lejimene          #+#    #+#              #
#    Updated: 2023/09/23 18:55:44 by lejimene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
CC	     	= cc
FLAGS    	= -Wall -Werror -Wextra -g 
LIBS		= printf/libftprintf.a
PRINTF	= ./printf/libftprintf.a
INCLUDE = -L ./printf -lft

SRC = main.c signal.c parser.c tokenize.c checks.c error.c 

OBJ	= ${SRC:.c=.o}
HEADER = minishell.h

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ} ${HEADER}
	make -C printf
	@${CC} ${FLAGS} ${OBJ} -lreadline -o  ${NAME} ${PRINTF}

all : ${NAME}

clean :
	@make clean -C printf
	@rm -f *.o

fclean: clean
	@make fclean -C printf
	@rm -f $(NAME)

re: fclean all