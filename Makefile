NAME = push_swap

FLAGS = -Wall -Wextra -Werror

SRC =	*.c

OBJ = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	gcc *.c libft.a -o $(NAME)

%.o : %.c
	gcc $(FLAGS) -c $<

fclean : clean
	rm -rf $(NAME) swap.a

clean :
	rm -rf $(OBJ)

re : fclean all