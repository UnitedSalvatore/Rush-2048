/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:14:50 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/22 21:42:22 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../include/game_2048.h"

int		main(void)
{
	t_data	game;

	ft_bzero(&game, sizeof(game));
	initialize(&game);
	check_win_value(game.win_value);
	generate_first_program_move(&game);
	while (42)
	{
		read_input(&game);
		if (game.game_mode == 0)
			menu_screen(&game);
		else if (game.game_mode == 1)
			update(&game);
		if (game.ch == ESC)
			break;
		game.ch = 0;
	}
	endwin();
	return (0);
}
