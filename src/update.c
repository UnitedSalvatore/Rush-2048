/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 16:03:47 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/21 18:04:57 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "2048.h"
#include <ncurses.h>

static	void update_resolution(t_data *game)
{
	int		size;

	size = MIN_BLOCK_SIZE * game->block_size + (game->map_size + 1);
	if (game->win_y < size || game->win_x < size)
		ft_error("Size of window less than min value", 2);
	
}

void	update(t_data *game)
{
	unsigned	win_y;
	unsigned	win_x;

	win_y = game->win_y;
	win_x = game->win_x;
	getmaxyx(game->main_win, game->win_y, game->win_x);
	if (win_y != game->win_y || win_x != game->win_x)
		update_resolution(game);
}
