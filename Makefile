NAME = minishell

SRC = main.c lexer.c print.c
OBJS = $(SRC:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	cc -Wall -Werror -Wextra -lreadline $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm $(NAME)

re: clean all
