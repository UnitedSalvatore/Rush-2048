/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:53:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/07/22 22:43:17 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_2048.h"

static void	set_number(t_data *game, unsigned *line_num, \
	unsigned *array_num, int set_type)
{
	if (*line_num != *array_num)
	{
		if (set_type == SET_TO_ARRAY)
		{
			game->player_moved = TRUE;
			*array_num = *line_num;
		}
		else if (set_type == SET_TO_LINE)
			*line_num = *array_num;
	}
}

static void	set_iterator_and_idx(unsigned *iterator, unsigned *idx,
								unsigned line_count)
{
	*iterator = 0;
	*idx = line_count;
}

static void	fill_line(t_data *game, unsigned line_count, int set_type, int ch)
{
	t_position	idx;
	t_position	iterator;
	unsigned	idx_line;

	if (ch == KEY_UP || ch == KEY_DOWN)
	{
		iterator.y = (ch == KEY_UP) ? 1 : -1;
		idx.y = (ch == KEY_UP) ? 0 : game->map_size - 1;
		set_iterator_and_idx(&(iterator.x), &(idx.x), line_count);
	}
	else
	{
		iterator.x = (ch == KEY_LEFT) ? 1 : -1;
		idx.x = (ch == KEY_LEFT) ? 0 : game->map_size - 1;
		set_iterator_and_idx(&(iterator.y), &(idx.y), line_count);
	}
	idx_line = 0;
	while (idx_line < game->map_size)
	{
		set_number(game, &(game->line[idx_line++]),
					&(game->blocks[idx.y][idx.x]), set_type);
		idx.y += iterator.y;
		idx.x += iterator.x;
	}
}

void		player_make_move(t_data *game)
{
	unsigned	line_count;

	game->player_moved = FALSE;
	line_count = 0;
	game->num_of_free_cell = 0;
	while (line_count < game->map_size)
	{
		fill_line(game, line_count, SET_TO_LINE, game->ch);
		handle_line(game);
		fill_line(game, line_count, SET_TO_ARRAY, game->ch);
		line_count++;
	}
}
