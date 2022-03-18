NAME	= Students

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra -g -include

DEPS	= students.h

SRCS	= students_utils.c students_input.c students_operations.c \
		students_output.c students.c

OBJS	= $(SRCS:.c=.o)

all: $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(DEPS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
