CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SRCS		= main.c \
			  count.c \
			  parse.c \
			  print_unit_sep.c \
			  search.c \
			  useful.c \
			  print_blocs.c \
			  add_dict.c

NAME		= rush-02
OBJS		= ${SRCS:.c=.o}

%.o:		%.c
			${CC} ${CFLAGS} -c $< -o $@

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

.PHONY:		all clean fclean
