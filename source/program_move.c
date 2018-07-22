/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:42:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/07/21 14:42:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		program_make_move(t_game_data *game)
{
	if (try_add_digit_to_game(game) == TRUE)
		return (TRUE);
	else
		return (FALSE);
}

int		try_add_digit_to_game(t_game_data *game)
{
	if (game->player_moved == FALSE)
		return (TRUE);
	else
	{
		if (game->num_of_free_cell > 0)
			generate_digit(game, game->num_of_free_cell);
		if (game->num_of_free_cell == 0)
		{
			if (check_possible_moves(game) == FALSE)
				return (FALSE);
			else
				return (TRUE);
		}
		else
			return (TRUE);
	}
}

int		check_possible_moves(t_game_data *game)
{
	int		possible_move;

	possible_move = 0;
	game->checking_mode = TRUE;
	handle_player_move(game, KEY_LEFT);
	possible_move += game->player_moved;
	handle_player_move(game, KEY_RIGHT);
	possible_move += game->player_moved;
	handle_player_move(game, KEY_UP);
	possible_move += game->player_moved;
	handle_player_move(game, KEY_DOWN);
	possible_move += game->player_moved;
	game->checking_mode = FALSE;
	if (possible_move == 0)
		return (FALSE);
	else
		return (TRUE);
}





/*void	fill_line(t_game_data *game, int line_count)//another version
{
	if (game->keycode == KEY_UP)
	{
		game->line[0] = game->game_array[0][line_count];
		game->line[1] = game->game_array[1][line_count];
		game->line[2] = game->game_array[2][line_count];
		game->line[3] = game->game_array[3][line_count];
	}
	else if (game->keycode == KEY_DOWN)
	{
		game->line[0] = game->game_array[3][line_count];
		game->line[1] = game->game_array[2][line_count];
		game->line[2] = game->game_array[1][line_count];
		game->line[3] = game->game_array[0][line_count];
	}
	else if (game->keycode == KEY_LEFT)
	{
		game->line[0] = game->game_array[line_count][0];
		game->line[1] = game->game_array[line_count][1];
		game->line[2] = game->game_array[line_count][2];
		game->line[3] = game->game_array[line_count][3];
	}
	else
	{
		game->line[0] = game->game_array[line_count][3];
		game->line[1] = game->game_array[line_count][2];
		game->line[2] = game->game_array[line_count][1];
		game->line[3] = game->game_array[line_count][0];
	}
}*/