/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:03:47 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/22 22:36:43 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_2048.h"
#include <ncurses.h>
#include <stdlib.h>

void		update(t_data *game)
{
	unsigned	win_y;
	unsigned	win_x;

	win_y = game->win_y;
	win_x = game->win_x;
	getmaxyx(game->main_win, game->win_y, game->win_x);
	if (win_y != game->win_y || win_x != game->win_x ||
		game->ch == KEY_DOWN || game->ch == KEY_UP ||
		game->ch == KEY_LEFT || game->ch == KEY_RIGHT)
	{
		player_make_move(game);
		if (program_make_move(game) == FALSE)
		{
			game->game_mode = LOSE_MODE;
			update_lose(game);
		}
		update_resolution(game);
		update_frame(game);
		update_blocks(game);
	}
	else if (game->ch == ESC)
		return ;
	wrefresh(game->main_win);
}
