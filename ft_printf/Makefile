NAME = libftprintf.a
SOURCES = ft_printf.c
LIBFT_SOURCES = libft/ft_putchar_fd.c libft/ft_putnbr_fd.c libft/ft_putstr_fd.c libft/ft_strlen.c
OBJECTS = $(SOURCES:.c=.o)
LIBFT_OBJECTS = $(LIBFT_SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) libft
	$(AR) rcs $@ $(OBJECTS) $(LIBFT_OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C libft

clean:
	rm -f $(OBJECTS) $(LIBFT_OBJECTS)
	make -C libft clean

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean clean all

.PHONY: all bonus libft clean fclean re