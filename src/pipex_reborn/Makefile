NAME = pipex
SRC = main.c path.c exec_pipe.c file_utils.c
OBJ = $(SRC:%.c=%.o)
INC = -Ilibft
LIB = libft/libft.a
LIBFTFLAGS = -Llibft -lft
LIBFT = libft/
CC = clang
CFLAGS = -Wall -Werror -Wextra -g3

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFTFLAGS)

$(LIB):
	make -C $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) $< -c -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:
	all clean fclean re
