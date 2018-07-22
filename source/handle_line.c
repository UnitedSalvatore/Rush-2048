/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:39:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/07/22 13:39:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	handle_line(t_game_data *game)
{
	move_numbers_left(game);
	if (is_same(game->line, 0, 1))
		is_same(game->line, 2, 3);
	else
	{
		if (!is_same(game->line, 1, 2))
			is_same(game->line, 2, 3);
	}
	move_numbers_left(game);
	game->num_of_free_cell += count_num_of_free_cell(game->line, game->array_size);
}

void	move_numbers_left(t_game_data *game)
{
	int		get_idx;
	int		set_idx;

	get_idx = 0;
	set_idx = 0;
	while (get_idx < game->array_size)
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

int		is_same(int *line, int idx_1, int idx_2)
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

int		count_num_of_free_cell(int *line, int line_size)
{
	int idx;
	int num_of_free_cell;

	num_of_free_cell = 0;
	idx = line_size - 1;
	while (idx >= 0 && line[idx] == 0)
	{
		num_of_free_cell++;
		idx--;
	}
	return (num_of_free_cell);
}
