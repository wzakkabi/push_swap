NAME = push_swap

FLAGS = -Wall -Wextra -Werror

SRC =	*.c

OBJ = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs swap.a $(OBJ)
	gcc $(FLAGS) swap.a libft.a -o $(NAME)

%.o : %.c
	gcc $(FLAGS) -c $<

fclean : clean
	rm -rf $(NAME) swap.a

clean :
	rm -rf $(OBJ)

re : fclean all