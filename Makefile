# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejokim <sejokim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 16:05:46 by sejokim           #+#    #+#              #
#    Updated: 2023/06/23 16:06:33 by sejokim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./main.c ./minishell_utils.c ./parsing.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

COMFILE_FLAGS = -lreadline -L${HOME}/.brew/opt/readline/lib
OBJ_FLAGS = -I${HOME}/.brew/opt/readline/include

RM = rm -rf

NAME = minishell

OBJS = ${SRCS:.c=.o}

all	: ${NAME}

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(COMFILE_FLAGS) $(OBJS) -o $(NAME) 

%.o: %.c
	$(CC) $(CFLAGS) $(OBJ_FLAGS) -c $< -o $@

clean	:
	${RM} ${SRCS:.c=.o}

fclean	:	clean
	${RM} ${NAME}  

re	:
	make fclean
	make all

.PHONY	:	clean fclean re all