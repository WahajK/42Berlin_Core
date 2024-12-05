CC = cc
CFLAG = -Wall -Wextra -Werror
NAME = libftprintf.a
SOURCES = ft_printf.c 
OBJECTS = $(SOURCES:.c=.o)
LIBFT = libft.a
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/$(LIBFT)
LIBFT_MAKE = make -C $(LIBFT_DIR) # -C flag is used to change directory to LIBFT_DIR
LIBFT_CLEAN = make clean -C $(LIBFT_DIR)
LIBFT_FCLEAN = make fclean -C $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(LIBFT_MAKE)
	cp $(LIBFT_LIB) $(NAME)
	ar rcs $(NAME) $(OBJECTS)