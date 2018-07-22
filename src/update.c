/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:03:47 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/22 16:46:38 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_2048.h"
#include <ncurses.h>

void		update(t_data *game)
{
	unsigned	win_y;
	unsigned	win_x;

	win_y = game->win_y;
	win_x = game->win_x;
	getmaxyx(game->main_win, game->win_y, game->win_x);
	if (win_y != game->win_y || win_x != game->win_x)
	{
		update_resolution(game);
		update_frame(game);
		update_blocks(game);
	}
	else if (game->ch)
		update_blocks(game);
	wrefresh(game->main_win);
}
