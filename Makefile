CC = gcc -Wall -Werror -Wextra

SRC = ft_pipex.c split.c utils.c utils2.c

OBJ = $(SRC:.c=.o)

NAME = pipex

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean main

.PHONY: all main clean fclean re