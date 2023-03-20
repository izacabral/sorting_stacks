SRCS	=	stack_sorting.c \
			stacks.c \
			stacks2.c \
			operations_swap.c \
			operations_push.c \
			operations_rotate.c \
			operations_revrotate.c \
			validation.c \
			validation2.c \
			sorting.c \
			sorting2.c \
			utils_extra.c

OBJS	=	$(SRCS:.c=.o)

NAME	=	stack_sorting

LIBC	=	mylibc.a

CC		=	cc

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror 

MLIBC	=	make -C mylibc && cp mylibc/$(LIBC) $(LIBC)

RMLIBC	=	make -C mylibc clean

FCLIBC	=	make -C mylibc fclean

.c.o: 
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(LIBC):	
			$(MLIBC)

$(NAME):	$(LIBC) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(LIBC) -o $(NAME)


clean:
			$(RM) $(OBJS)
			$(RM) $(LIBC)
			$(RMLIBC)

fclean:		clean
			$(RM) $(NAME)
			$(FCLIBC)

re:			fclean all

.PHONY:		all clean fclean re

