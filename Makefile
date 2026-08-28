NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
CPPFLAGS = -MMD -MP

SRC = main.c push_swap.c split.c parse.c parse_number.c count_elements.c \
	parse_flags.c disorder.c \
	check_duplicates.c stack_init.c \
	op_swap.c op_push.c \
	op_rotate.c op_reverse.c \
	sort_small.c sort_helpers.c sort_radix.c sort_chunk.c \
	utils.c utils_chunk.c operation_log.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

-include $(OBJ:.o=.d)

clean:
	rm -f $(OBJ) $(OBJ:.o=.d)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re