/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:14:36 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/22 21:53:36 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <string.h>
# include <ncurses.h>

# define DEFAULT_MAP_SIZE 4u
# define MIN_BLOCK_X 6u
# define MIN_BLOCK_Y 3u
# define MAX_MAP_SIZE 5u
# define MENU_MODE 0
# define GAME_MODE 1
# define LOSE_MODE 4

static const char	g_logo[7][52] = {
	"        ::::::::   :::::::      :::      :::::::: ",
	"      :+:    :+: :+:   :+:    :+:      :+:    :+: ",
	"           +:+  +:+   +:+   +:+ +:+   +:+    +:+  ",
	"        +#+    +#+   +:+  +#+  +:+    +#++:++#    ",
	"     +#+      +#+   +#+ +#+#+#+#+#+ +#+    +#+    ",
	"   #+#       #+#   #+#       #+#   #+#    #+#     ",
	" ##########  #######        ###    ########       ",
};

typedef struct s_data	t_data;
typedef enum e_const	t_winv;
typedef struct s_position	t_position;

struct		s_position
{
	unsigned	x;
	unsigned	y;
};

typedef enum	e_const
{
	NONE = 0u,
	WIN_VALUE = 2048u
}				t_const;

struct			s_data
{
	t_const		win_value;
	unsigned	score;
	unsigned	map_size;
	unsigned	ch;
	unsigned	game_mode;

	unsigned	**blocks;
	unsigned	block_x;
	unsigned	block_y;

	WINDOW		*main_win;
	unsigned	win_x;
	unsigned	win_y;
	unsigned	win_max_x;
	unsigned	win_max_y;

	\

	unsigned	num_of_free_cell;
	unsigned	player_moved;
	unsigned	game_over;
	unsigned	*line;
};

/*
**	initialize.c
*/
void			read_input(t_data *game);

/*
**	menu.c
*/
void			menu_screen(t_data *game);

/*
**	initialize.c
*/
void			initialize(t_data *game);

/*
**	update.c
*/
void			update(t_data *game);

/*
**	utils.c
*/
void			update_resolution(t_data *game);
void			update_blocks(t_data *game);
void			update_frame(t_data *game);

/*
**	utils.c
*/
void			ft_error(const char *message, int exit_code);
unsigned		numlen(unsigned num);

/*
**----------------------------------dadavyde----------------------------------
*/

# define ESC 27

enum			e_error {BAD_WIN_VALUE, TO_SMALL_WINDOW};
enum			e_set {SET_TO_LINE, SET_TO_ARRAY};

/*
**	utils.c
*/
void			check_win_value(t_winv win_value);
void			error_exit(int error_name, t_data *game);

/*
**	generate_digits.c
*/
void			generate_first_program_move(t_data *game);
void			generate_digit(t_data *game, unsigned num_of_free_cell);

/*
**	player_move.c
*/
void			player_make_move(t_data *game);

/*
**	handle_line.c
*/
void			handle_line(t_data *game);
void			move_numbers_left(t_data *game);
unsigned		is_same(unsigned *line, unsigned idx_1, unsigned idx_2);
unsigned		count_free_cells(unsigned *line, unsigned line_size);

/*
**	program_move.c
*/
int				program_make_move(t_data *game);

#endif
