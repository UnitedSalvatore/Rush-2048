/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inialize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:39:55 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/21 18:05:00 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <ncurses.h>
#include <string.h>

static	ncurses(t_data *game)
{
	if (!(game->main_win = initscr()))
		ft_error("Error while inialize ncurses mode", 1);
	if (cbreak() == ERR || \
		noecho() == ERR || \
		keypad(game->main_win, TRUE))
		ft_error("Error while inialize ncurses mode", 1);
	curs_set(0);
	srand(time(NULL));
}

static game_data(t_data game)
{
	
	game->map_size = DEFAULT_MAP_SIZE;
	getmaxyx(game->main_win, game->win_y, game->win_x);
	if (game->win_y <  || \
		game->win_x < MIN_WINY_SIZE)
		ft_error("Size of window less than min value", 2);

}

void	inialize(t_data *game)
{
	ncurses(game);
	game_data(game);
}
