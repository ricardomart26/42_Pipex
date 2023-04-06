CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

SRC = ft_pipex.c split.c utils.c utils2.c

OBJ = $(SRC:.c=.o)

NAME = pipex

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all main clean fclean re