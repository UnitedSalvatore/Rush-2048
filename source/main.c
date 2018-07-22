/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 12:07:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/07/21 12:07:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"


void	print_game(t_game_data *game);

int		main(void)
{
	t_game_data		game;

	check_win_value();
	init_game(&game);
	generate_first_program_move(&game);
	//print_game(&game);
	while (TRUE)
	{
		clear();//TODO delete
		print_game(&game);//TODO delete
		if (player_make_move(&game) == FALSE)
			break ;
		if (program_make_move(&game) == FALSE)
			break ;
		refresh();
	}
	free_array(&game);
	endwin(); // завершение работы с ncurses
	return (0);
}

void	print_game(t_game_data *game)
{
	t_position	idx;

	idx.y = 0;
	while (idx.y < game->array_size)
	{
		idx.x = 0;
		while (idx.x < game->array_size)
		{
			mvprintw(idx.y * 4, idx.x * 4, "%d", game->game_array[idx.y][idx.x]);
			idx.x++;
		}
		printw("\n");
		idx.y++;
	}
	printw("\n\n");
}