/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:16:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/07/21 14:16:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		check_win_value(t_game_data *game)
{
	int		value;

	value = game->win_value;
	if (value < 2)
		error_exit(BAD_WIN_VALUE, NULL);
	while (value > 1)
	{
		if (value % 2 != 0)
			break ;
		value /= 2;
	}
	if (value > 1)
		error_exit(BAD_WIN_VALUE, NULL);
	return (TRUE);
}

void	check_for_win_value(t_game_data *game)
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
				if (game->game_array[idx.y][idx.x] == WIN_VALUE)
				{
					game->win_value = NONE;
					return;
				}
			}
			idx.x++;
		}
		idx.y++;
	}
}