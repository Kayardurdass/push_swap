SRCS = 
SRC_BONUS = 
OBJS = ${SRCS:.c=.o}

SRCSALL = ${SRCS} ${SRC_BONUS}

OBJSALL = ${SRCSALL:.c=.o}

LIB = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${LIB}:	${OBJS}
	ar -rsc ${LIB} ${OBJS}

all: 	${LIB}

bonus:	${OBJSALL}
	ar -rsc ${LIB} ${OBJSALL}
	

clean:	
		rm -f ${OBJS}

fclean:	clean;
		rm -f ${LIB}

re:	fclean all

.PHONY: all clean fclean re bonus
