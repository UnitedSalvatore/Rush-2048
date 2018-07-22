NAME = game_2048

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

FILENAMES = main.c \
			initialize.c \
			update.c \
			utils.c

SOURCES = $(addprefix ./src/, $(FILENAMES))
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
FLAGS ?= -Wall -Wextra -Werror
FLAGS += -I./inc/

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) -o $@ $(FLAGS) $(OBJECTS) $(LIBFT) -lncurses

$(LIBFT):
	make -C $(LIBFT_DIR)/

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)
	make -C $(LIBFT_DIR)/ fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
