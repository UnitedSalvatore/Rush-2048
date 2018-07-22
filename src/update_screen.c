/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 16:13:56 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/22 22:42:58 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_2048.h"
#include <ncurses.h>

static unsigned	get_color(const unsigned col)
{
	if (col == 2)
		return (3);
	if (col == 4)
		return (4);
	if (col == 8)
		return (5);
	if (col == 16)
		return (6);
	if (col == 32)
		return (7);
	if (col == 64)
		return (8);
	if (col == 128)
		return (9);
	if (col == 256)
		return (10);
	if (col == 512)
		return (11);
	if (col == 1024)
		return (12);
	if (col == 2048)
		return (13);
	return (14);
}

void			update_resolution(t_data *game)
{
	unsigned	size_x;
	unsigned	size_y;

	size_x = MIN_BLOCK_X * game->map_size + (game->map_size + 1);
	size_y = MIN_BLOCK_Y * game->map_size + (game->map_size + 1) + 1;
	if (game->win_y < size_x || game->win_x < size_y)
	{
		werase(game->main_win);
		wrefresh(game->main_win);
		ft_error("Size of window less than min value", 2);
	}
	game->block_x = (game->win_x - (game->map_size + 1)) / game->map_size;
	game->block_y = (game->win_y - (game->map_size + 1) - 1) / game->map_size;
	game->win_max_x = game->block_x * game->map_size + (game->map_size + 1);
	game->win_max_y = game->block_y * game->map_size + (game->map_size + 1);
}

void			update_blocks(t_data *game)
{
	unsigned	y;
	unsigned	x;

	y = 0;
	while (y < game->map_size)
	{
		x = 0;
		while (x < game->map_size)
		{
			if (game->blocks[y][x])
			{
				attron(COLOR_PAIR(get_color(game->blocks[y][x])));
				mvwprintw(game->main_win, \
					(y + 1) + (y * game->block_y) + (game->block_y / 2), \
					x + (x * game->block_x) + (game->block_x / 2 \
						- (numlen(game->blocks[y][x]) / 2)), \
					"%d", game->blocks[y][x]);
			}
			++x;
		}
		++y;
	}
	mvwprintw(game->main_win, game->win_max_y, 0, "Score: %u", game->score);
}

void			update_frame(t_data *game)
{
	unsigned	i;

	i = 0;
	werase(game->main_win);
	attron(COLOR_PAIR(1));
	while (i < game->map_size + 1)
	{
		mvwhline(game->main_win, i * game->block_y + i, 0, '#', \
			game->win_max_x);
		mvwvline(game->main_win, 0, i * game->block_x + i, '#', \
			game->win_max_y);
		++i;
	}
	attroff(COLOR_PAIR(1));
}
