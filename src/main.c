/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:14:50 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/22 22:11:54 by ypikul           ###   ########.fr       */
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
		if (game.game_mode == MENU_MODE)
			menu_screen(&game);
		else if (game.game_mode == GAME_MODE)
			update(&game);
		else if (game.game_mode == LOSE_MODE)
			lose_screen(&game);
		else if (game.game_mode == WIN_MODE)
			finish_screen(&game);
		else if (game.game_mode == LOSE_MODE)
			lose_screen(&game);
		game.ch = 0;
	}
	endwin();
	return (0);
}
