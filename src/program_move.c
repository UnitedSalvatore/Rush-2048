/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:42:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/07/22 22:21:04 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_2048.h"

static int	check_possible_moves(t_data *game)
{
	t_position	idx;

	idx.y = 0;
	while (idx.y < game->map_size)
	{
		idx.x = 0;
		while (idx.x < game->map_size)
		{
			if (idx.y > 0)
			{
				if (game->blocks[idx.y][idx.x] ==
					game->blocks[idx.y - 1][idx.x])
					return (TRUE);
			}
			if (idx.x < game->map_size - 1)
			{
				if (game->blocks[idx.y][idx.x] ==
					game->blocks[idx.y][idx.x + 1])
					return (TRUE);
			}
			idx.x++;
		}
		idx.y++;
	}
	return (FALSE);
}

static int	try_add_digit_to_game(t_data *game)
{
	if (game->player_moved == FALSE)
		return (TRUE);
	else
	{
		if (game->num_of_free_cell != 0)
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

static void	check_for_win_value(t_data *game)
{
	t_position	idx;

	idx.y = 0;
	while (idx.y < game->map_size)
	{
		idx.x = 0;
		while (idx.x < game->map_size)
		{
			if (idx.y > 0)
			{
				if (game->blocks[idx.y][idx.x] == WIN_VALUE)
				{
					game->win_value = NONE;
					return ;
				}
			}
			idx.x++;
		}
		idx.y++;
	}
}

int			program_make_move(t_data *game)
{
	if (game->win_value != NONE)
		check_for_win_value(game);
	if (game->win_value == NONE)
		return (TRUE);
	if (try_add_digit_to_game(game) == TRUE)
		return (TRUE);
	else
		return (FALSE);
}
