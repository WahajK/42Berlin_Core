NAME = libft.a

SRCS = ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_strlen.c

OBJ = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) -r $@ $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re