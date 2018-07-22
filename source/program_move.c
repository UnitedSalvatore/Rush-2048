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
	if (game->win_value != NONE)
		check_for_win_value(game);
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
	t_position	idx;

	idx.y = 0;
	while (idx.y < game->array_size)
	{
		idx.x = 0;
		while (idx.x < game->array_size)
		{
			if (idx.y > 0)
			{
				if (game->game_array[idx.y][idx.x] == game->game_array[idx.y - 1][idx.x])
					return (TRUE);
			}
			if (idx.x < game->array_size - 1)
			{
				if (game->game_array[idx.y][idx.x] == game->game_array[idx.y][idx.x + 1])
					return (TRUE);
			}
			idx.x++;
		}
		idx.y++;
	}
	return (FALSE);
}
