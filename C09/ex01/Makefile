# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spoliart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 18:09:28 by spoliart          #+#    #+#              #
#    Updated: 2020/09/29 00:33:21 by spoliart         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a
SRCS =		srcs/ft_putchar.c

OBJS =		${SRCS:.c=.o}

CC =		gcc
RM =		rm -f

CFLAGS =	-Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I includes -c $< -o ${<:.c=.o}

$(NAME): 	${OBJS}
			ar rcs ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
