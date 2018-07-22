/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 17:47:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/07/21 17:47:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	generate_first_program_move(t_game_data *game)
{
	srand ((unsigned int)time(NULL));
	generate_digit(game, game->array_size * game->array_size);
	generate_digit(game, game->array_size * game->array_size - 1);
}

void	generate_digit(t_game_data *game, int num_of_free_cell)
{
	int			digit_idx;
	int			digit;

	if (num_of_free_cell > 1)
		digit_idx = (rand() % num_of_free_cell);
	else
		digit_idx = 0;
	digit = (rand() % 6);//TODO check
	digit = (digit == 4) ? 4 : 2;
	set_digit(game, digit_idx, digit);
	game->num_of_free_cell--;
}


void	set_digit(t_game_data *game, int digit_idx, int digit)
{
	t_position	idx;

	idx.y = 0;
	while (idx.y < game->array_size)
	{
		idx.x = 0;
		while (idx.x < game->array_size)
		{
			if (game->game_array[idx.y][idx.x] == 0)
			{
				if (digit_idx == 0)
				{
					game->game_array[idx.y][idx.x] = digit;
					return ;
				}
				digit_idx--;
			}
			idx.x++;
		}
		idx.y++;
	}
	game->game_array[0][0] = 11;//TODO delete
}

