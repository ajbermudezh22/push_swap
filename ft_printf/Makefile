NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o) 
LIBFT = ../libft/libft.a

all: $(NAME)

$(LIBFT):
	make -C ../libft

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make clean -C ../libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ../libft

re: fclean all

test: $(NAME)
	$(CC) $(CFLAGS) -o test test.c -L. -lftprintf
	./test

.PHONY: all clean fclean re test

