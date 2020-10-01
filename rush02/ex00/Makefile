REPO	= ./
SRCS	= ${REPO}basics.c ${REPO}dict_to_struct.c ${REPO}ft_gest_error.c \
		  ${REPO}count.c ${REPO}entry_dict.c ${REPO}ft_write.c \
		  ${REPO}main.c  ${REPO}nbr_mod.c  ${REPO}nbr_others.c \
		  ${REPO}nbr_principal.c
HEADER	= ./includes/

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

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
