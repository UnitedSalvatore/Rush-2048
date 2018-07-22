/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:49:19 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/22 17:48:06 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_2048.h"
#include <ncurses.h>

#define MAX_Y game->map_size * game->block_y + game->map_size
#define MAX_X game->map_size * game->block_x + game->map_size
#define X_START game->win_max_x / 2 - 25
#define Y_START game->win_max_y / 10

static void	update_menu(t_data *game)
{
	werase(game->main_win);
	attron(COLOR_PAIR(2));
	mvwprintw(game->main_win, Y_START + 1, X_START, "%s", g_logo[0]);
	mvwprintw(game->main_win, Y_START + 2, X_START, "%s", g_logo[1]);
	mvwprintw(game->main_win, Y_START + 3, X_START, "%s", g_logo[2]);
	mvwprintw(game->main_win, Y_START + 4, X_START, "%s", g_logo[3]);
	mvwprintw(game->main_win, Y_START + 5, X_START, "%s", g_logo[4]);
	mvwprintw(game->main_win, Y_START + 6, X_START, "%s", g_logo[5]);
	mvwprintw(game->main_win, Y_START + 7, X_START, "%s", g_logo[6]);
	mvwprintw(game->main_win, game->win_max_y / 2, X_START, "%s", \
		"1 : Play!");
	attron(COLOR_PAIR(1));
	mvwhline(game->main_win, 0, 0, '#', game->win_max_x);
	mvwhline(game->main_win, 0, 0, '#', game->win_max_x);
	mvwhline(game->main_win, MAX_Y + 1, 0, '#', game->win_max_x);
	mvwvline(game->main_win, 0, 0, '#', game->win_max_y);
	mvwvline(game->main_win, 0, MAX_X, '#', game->win_max_y);
	attroff(COLOR_PAIR(1));
}

void		menu(t_data *game)
{
	unsigned	win_y;
	unsigned	win_x;

	win_y = game->win_y;
	win_x = game->win_x;
	getmaxyx(game->main_win, game->win_y, game->win_x);
	if (win_y != game->win_y || win_x != game->win_x)
	{
		update_resolution(game);
		update_menu(game);
	}
	if (game->ch)
	{
		game->game_mode = 1;
		update_frame(game);
	}
	wrefresh(game->main_win);
}
