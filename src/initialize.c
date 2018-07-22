/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 11:04:01 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/22 13:21:09 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../include/2048.h"
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

static void	ncurses(t_data *game)
{
	if (!(game->main_win = initscr()))
		ft_error("Error while inialize ncurses mode", 1);
	start_color();
	if (cbreak() == ERR || \
		noecho() == ERR || \
		keypad(game->main_win, TRUE))
		ft_error("Error while inialize ncurses mode", 1);
	curs_set(0);
	srand(time(NULL));
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
}

static void	game_data(t_data *game)
{
	unsigned	i;
	unsigned	j;

	game->map_size = DEFAULT_MAP_SIZE;
	game->block_x = MIN_BLOCK_X;
	game->block_y = MIN_BLOCK_Y;
	game->win_value = WIN_VALUE;
	if (!game->map_size)
		ft_error("Wrong map size", 0);
	i = 0;
	j = 0;
	game->blocks = ft_memalloc(sizeof(t_block *) * game->map_size);
	while (i < game->map_size)
		game->blocks[i++] = ft_memalloc(sizeof(t_block) * game->map_size);
}

void		initialize(t_data *game)
{
	ncurses(game);
	game_data(game);
}
