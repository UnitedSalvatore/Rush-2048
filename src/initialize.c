/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 11:04:01 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/22 21:13:28 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../include/game_2048.h"
#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

static void	init_pairs(void)
{
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, 101, COLOR_BLACK);
	init_pair(4, 102, COLOR_BLACK);
	init_pair(5, 103, COLOR_BLACK);
	init_pair(6, 104, COLOR_BLACK);
	init_pair(7, 105, COLOR_BLACK);
	init_pair(8, 106, COLOR_BLACK);
	init_pair(9, 107, COLOR_BLACK);
	init_pair(10, 108, COLOR_BLACK);
	init_pair(12, 109, COLOR_BLACK);
	init_pair(13, 110, COLOR_BLACK);
	init_pair(14, 111, COLOR_BLACK);
}

static void	init_colors(void)
{
	init_color(102, 600, 600, 500);
	init_color(103, 500, 700, 500);
	init_color(104, 500, 100, 500);
	init_color(105, 900, 500, 500);
	init_color(106, 500, 500, 800);
	init_color(107, 500, 300, 500);
	init_color(108, 500, 500, 500);
	init_color(109, 100, 100, 500);
	init_color(110, 500, 500, 500);
	init_color(111, 100, 300, 500);
}

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
	nodelay(game->main_win, TRUE);
}

static void	game_data(t_data *game)
{
	unsigned	i;
	unsigned	j;

	game->map_size = DEFAULT_MAP_SIZE;
	game->block_x = MIN_BLOCK_X;
	game->block_y = MIN_BLOCK_Y;
	game->win_value = WIN_VALUE;
	game->ch = '\0';
	if (!game->map_size)
		ft_error("Wrong map size", 0);
	i = 0;
	j = 0;
	game->blocks = ft_memalloc(sizeof(unsigned *) * game->map_size);
	while (i < game->map_size)
		game->blocks[i++] = ft_memalloc(sizeof(unsigned) * game->map_size);
	game->line = ft_memalloc(sizeof(int) * game->map_size);
	game->num_of_free_cell = game->map_size * game->map_size;
}

void		initialize(t_data *game)
{
	ncurses(game);
	game_data(game);
	init_colors();
	init_pairs();
}
