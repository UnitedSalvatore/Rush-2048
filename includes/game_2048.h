/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:28:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/07/21 12:28:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "libft.h"

#define ESC 27

enum	e_error {BAD_WIN_VALUE, TO_SMALL_WINDOW};
enum	e_set {SET_TO_LINE, SET_TO_ARRAY};

typedef enum	e_const
{
	NONE = 0u,
	WIN_VALUE = 2048u
}				t_const;

typedef struct		s_game_data
{
	int				keycode;
	int				array_size;
	int				**game_array;
	int				*line;
	int				player_moved;
	int				num_of_free_cell;
	int				score;//added

	t_const			win_value;
	unsigned		map_size;
	unsigned		ch;
	unsigned		game_mode;

	unsigned		**blocks;
	unsigned		block_x;
	unsigned		block_y;

	WINDOW			*main_win;
	unsigned		win_x;
	unsigned		win_y;
	unsigned		win_max_x;
	unsigned		win_max_y;
}					t_game_data;

typedef struct		s_position
{
	int				x;
	int				y;
}					t_position;

int		check_win_value(t_game_data *game);
void	check_for_win_value(t_game_data *game);

void	init_game(t_game_data *game);
void	choose_game_and_load(t_game_data *game);

void	generate_first_program_move(t_game_data *game);
void	generate_digit(t_game_data *game, int num_of_free_cell);
void	set_digit(t_game_data *game, int digit_idx, int digit);

int		player_make_move(t_game_data *game);
void	player_press_key(t_game_data *game);
int		handle_player_move(t_game_data *game);
void	fill_line(t_game_data *game, int line_count, int set_type, int keycode);
void	set_number(t_game_data *game, int *line_num, int *array_num, int set_type);

void	handle_line(t_game_data *game);
void	move_numbers_left(t_game_data *game);
int		is_same(int *line, int idx_1, int idx_2);
int		count_free_cells(int *line, int line_size);

int		program_make_move(t_game_data *game);
int		try_add_digit_to_game(t_game_data *game);
int		check_possible_moves(t_game_data *game);

void	error_exit(int error_name, t_game_data *game);
void	free_array(t_game_data *game);

#endif
