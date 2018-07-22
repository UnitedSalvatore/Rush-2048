/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 20:04:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/07/21 20:04:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	init_game(t_game_data *game)
{
	int		j;

	j = 0;
	srand((unsigned int)time(NULL));
	choose_game_and_load(game);
	game->game_array = malloc(sizeof(int*) * game->array_size);
	while (j < game->array_size)
	{
		game->game_array[j] = ft_memalloc(sizeof(int) * game->array_size);
		j++;
	}
	game->line = ft_memalloc(sizeof(int) * game->array_size);
	game->checking_mode = FALSE;
	game->num_of_free_cell = game->array_size * game->array_size;
	initscr();//инициализация библиотеки
	keypad(stdscr, TRUE);//режим обработки командных клавиш //int keypad(WINDOW *win, bool bf)
}

void	choose_game_and_load(t_game_data *game)
{
	game->array_size = 4;//TODO дописать
	//
}
