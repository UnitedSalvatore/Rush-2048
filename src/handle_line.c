/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:39:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/07/22 19:53:46 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_2048.h"

void	handle_line(t_data *game)
{
	move_numbers_left(game);
	if (is_same(game->line, 0, 1))
	{
		game->score += game->line[0];
		if (is_same(game->line, 2, 3))
			game->score += game->line[2];
	}
	else
	{
		if (is_same(game->line, 1, 2))
			game->score += game->line[1];
		else
		{
			if (is_same(game->line, 2, 3))
				game->score += game->line[2];
		}
	}
	move_numbers_left(game);
	game->num_of_free_cell += count_free_cells(game->line, game->map_size);
}

void	move_numbers_left(t_data *game)
{
	unsigned		get_idx;
	unsigned		set_idx;

	get_idx = 0;
	set_idx = 0;
	while (get_idx < game->map_size)
	{
		if (game->line[get_idx] != 0)
		{
			if (set_idx != get_idx)
			{
				game->line[set_idx] = game->line[get_idx];
				game->line[get_idx] = 0;
			}
			set_idx++;
		}
		get_idx++;
	}
}

unsigned		is_same(unsigned *line, unsigned idx_1, unsigned idx_2)
{
	if (line[idx_1] == line[idx_2])
	{
		line[idx_1] += line[idx_2];
		line[idx_2] = 0;
		return (TRUE);
	}
	else
		return (FALSE);
}

unsigned		count_free_cells(unsigned *line, unsigned line_size)
{
	int		 idx;
	unsigned num_of_free_cell;

	num_of_free_cell = 0;
	idx = line_size - 1;
	while (idx >= 0 && line[idx] == 0)
	{
		num_of_free_cell++;
		idx--;
	}
	return (num_of_free_cell);
}
