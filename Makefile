NAME = push_swap

FLAGS = -Wall -Wextra -Werror

SRC =	ft_atoi.c ft_bzero.c ft_calloc.c ft_split.c ft_strlen.c ft_substr.c helper_function2.c operation2.c operation3.c operations.c push_swap.c sort2_3_5.c

OBJ = $(SRC:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(FLAGS) $(SRC) -o $(NAME)

%.o : %.c
	gcc $(FLAGS) -c $<

fclean : clean
	rm -rf $(NAME) swap.a

clean :
	rm -rf $(OBJ)

re : fclean all