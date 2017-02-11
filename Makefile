NAME		=	bfi

CC		=	gcc

RM		=	rm -rf

SRCS		=	src/main.c		\
			src/parser.c		\
			src/init.c		\
			src/interpretor.c	\
			src/loops.c

OBJS		=	$(SRCS:.c=.o)

CPPFLAGS	=	-I./include/

CFLAGS		=	-W -Wall -Wextra


all:		$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

$(NAME):	all

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

debug:		CFLAGS += -g
debug:		re
