/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 17:47:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/07/22 22:22:44 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_2048.h"
#include <stdlib.h>

void		generate_first_program_move(t_data *game)
{
	generate_digit(game, game->num_of_free_cell);
	generate_digit(game, game->num_of_free_cell - 1);
}

static void	set_digit(t_data *game, unsigned digit_idx, unsigned digit)
{
	t_position	idx;

	idx.y = 0;
	while (idx.y < game->map_size)
	{
		idx.x = 0;
		while (idx.x < game->map_size)
		{
			if (game->blocks[idx.y][idx.x] == 0)
			{
				if (digit_idx == 0)
				{
					game->blocks[idx.y][idx.x] = digit;
					return ;
				}
				digit_idx--;
			}
			idx.x++;
		}
		idx.y++;
	}
}

void		generate_digit(t_data *game, unsigned num_of_free_cell)
{
	unsigned	digit_idx;
	unsigned	digit;

	if (num_of_free_cell > 1)
		digit_idx = (rand() % num_of_free_cell);
	else
		digit_idx = 0;
	digit = (rand() % 6);
	digit = (digit == 4) ? 4 : 2;
	set_digit(game, digit_idx, digit);
	game->num_of_free_cell--;
}
