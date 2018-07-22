/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:14:36 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/22 13:39:03 by ypikul           ###   ########.fr       */
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

typedef struct s_data	t_data;
typedef	struct s_block	t_block;
typedef enum e_const	t_winv;

typedef enum	e_const
{
	WIN_VALUE = 2048u
}				t_winv;

struct			s_data
{
	size_t		score;
	unsigned	map_size;
	t_winv		win_value;
	char		ch;

	t_block		**blocks;
	unsigned	block_x;
	unsigned	block_y;

	WINDOW		*main_win;
	unsigned	win_x;
	unsigned	win_y;
	unsigned	win_max_x;
	unsigned	win_max_y;
};

struct			s_block
{
	unsigned	active;
	unsigned	value;
};

// enum			e_direction
// {
// 	UP, DOWN, LEFT, RIGHT
// };

/*
**	utils.c
*/
void	ft_error(const char *message, int exit_code);

/*
**	update.c
*/
void	update(t_data *game);

/*
**	initialize.c
*/
void	initialize(t_data *game);

#endif
