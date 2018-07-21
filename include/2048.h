/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:14:36 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/21 18:04:55 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 2048_H
# define 2048_H

# include <string.h>
# include <ncurses.h>

# define DEFAULT_MAP_SIZE 4u
# define MIN_BLOCK_SIZE 6u
# define MAX_MAP_SIZE 5u

typedef s_data	t_data;
typedef	s_block	t_block;

struct			s_data
{
	size_t		score;
	unsigned	map_size;
	unsigned	block_size;
	t_block		*blocks[MAX_MAP_SIZE * MAX_MAP_SIZE];

	WINDOWS		*main_win;
	unsigned	win_x;
	unsigned	win_y;
	unsigned	win_max_x;
	unsigned	win_max_y;
};

struct			s_block
{
	size_t		value;
};

enum			e_const
{
	WIN_VALUE = 2048
};

enum			e_direction
{
	UP, DOWN, LEFT, RIGHT
};

#endif
