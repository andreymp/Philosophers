NAME =	philo

CC =	gcc
CFLAGS =	-g -Wall -Wextra -Werror -MMD

RM =	rm -rf

SRC =   utils.c \
		init.c \
		get_time.c \
		main.c \
		philo.c \

INC = 	-I philo.h \

OBJS =	$(SRC:.c=.o)
DEP =	$(SRC:.c=.d)

.PHONY :	all clean re fclean

.c.o :		
		${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}


$(NAME):	$(OBJS)
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: 		$(NAME)

clean:
			$(RM) $(OBJS) $(DEP)

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

-include $(DEP)