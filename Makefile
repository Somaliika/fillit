NAME = fillit
OBJECTS = *.o
MAIN = main.c
LIB = ./libft
INC = /includes
LIBNAME = libft.a
C = /*.c

all: $(NAME)

$(NAME):
	gcc -Wextra -Wall -Werror -c $(LIB)$(C) -I$(LIB)$(INC)
	ar rc $(LIBNAME) $(OBJECTS)
	gcc -Wextra -Wall -Werror  -c -I. -I$(LIB)$(INC) .$(C) 
	gcc -o $(NAME) $(OBJECTS) -L. -lft

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBNAME)

re: fclean all