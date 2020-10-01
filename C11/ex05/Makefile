REPO	= ./srcs/
SRCS	= ${REPO}ft_atoi.c ${REPO}ft_do_op.c ${REPO}ft_operations.c \
		  ${REPO}put.c ${REPO}op.c ${REPO}main.c
HEADER	= ./includes/

OBJS	= ${SRCS:.c=.o}

NAME	= do-op

FLAGS	= -Wall -Wextra -Werror
RM		= rm -f

.c.o:
			cc ${FLAGS} -c $< -o ${<:.c=.o} -I${HEADER}

$(NAME):	${OBJS}
			cc -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
