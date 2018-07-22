# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dadavyde <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 12:09:18 by dadavyde          #+#    #+#              #
#    Updated: 2018/07/21 12:09:21 by dadavyde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
C_FLAGS = -c -Wall -Wextra -Werror
NCURSES_FLAGS = -lncurses

SOURCES = source/main.c source/check_win_value.c source/error_exit.c\
			source/program_move.c source/player_move.c source/generate_digits.c\
			source/init_game.c source/handle_line.c

HEADERS = includes/game_2048.h
INCLUDES = -I libft/ -I includes/

OBJ = $(addprefix $(OBJDIR), $(notdir $(SOURCES:.c=.o)))
OBJDIR = obj/

LIBFT = libft/libft.a
NAME = game_2048

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(NCURSES_FLAGS) -o $@ $(LIBFT)

$(OBJDIR)%.o: source/%.c $(HEADERS) $(SOURCES) $(LIBFT) $(OBJDIR)
	$(CC) $(C_FLAGS) $< -o  $@ $(INCLUDES)

$(LIBFT):
	make -C libft

$(OBJDIR): $(HEADERS) $(LIBFT)
	mkdir -p $(OBJDIR)

clean:
	rm -f $(OBJ)
	rm -rf $(OBJDIR)

fclean: clean
	echo $(OBJ)
	rm -f $(NAME)

re: fclean all
