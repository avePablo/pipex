NAME = gnl.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRC =	get_next_line_utils.c \
		get_next_line.c 
		

 OBJ = $(SRC:.c=.o)


 all: $(NAME)

 $(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re