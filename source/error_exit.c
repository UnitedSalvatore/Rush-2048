/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:26:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/07/21 14:26:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	error_exit(int error_name, t_game_data *game)
{
	if (error_name == BAD_WIN_VALUE)
		printw("WIN_VALUE = %d is not power of 2. You cannot run the game!\n", WIN_VALUE);
	else if (error_name == TO_SMALL_WINDOW)
	{
		printw("Window too small. Exiting.");
		free_array(game);
	}
	exit(1);
}

void	free_array(t_game_data *game)
{
	int		j;

	j = 0;
	if (game != NULL)
	{
		while (j < game->array_size)
		{
			free(game->game_array[j]);
			j++;
		}
		free(game->game_array);
		free(game->line);
	}

}
