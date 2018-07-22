/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dadavyde <dadavyde@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:53:00 by dadavyde          #+#    #+#             */
/*   Updated: 2018/07/21 14:53:00 by dadavyde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		player_make_move(t_game_data *game)
{
	player_press_key(game);
	if (handle_player_move(game) == TRUE)
		return (TRUE);
	else
		return (FALSE);
}

void	player_press_key(t_game_data *game)
{
	int		first_key;
	int		second_key;

	while (TRUE)
	{
		first_key = getch(); // ждём нажатия символа
		if (first_key == KEY_DOWN || first_key == KEY_UP ||
			first_key == KEY_LEFT || first_key == KEY_RIGHT)
			break ;
		if (first_key == ESC)
		{
			nodelay(stdscr, TRUE);
			second_key = getch();
			//nodelay(stdscr, FALSE);
			if (second_key == -1)
				break ;
		}
	}
	game->keycode = first_key;
}

int		handle_player_move(t_game_data *game)
{
	int		line_count;

	if (game->keycode == ESC)
		return (FALSE);
	else
	{
		game->player_moved = FALSE;
		line_count = 0;
		game->num_of_free_cell = 0;
		while (line_count < game->array_size)
		{
			fill_line(game, line_count, SET_TO_LINE);
			handle_line(game);
			fill_line(game, line_count, SET_TO_ARRAY);
			line_count++;
		}
		return (TRUE);
	}
}

void	fill_line(t_game_data *game, int line_count, int set_type)
{
	t_position	idx;
	t_position	iterator;
	int			idx_line;

	if (game->keycode == KEY_UP || game->keycode == KEY_DOWN)
	{
		iterator.y = (game->keycode == KEY_UP) ? 1 : -1;
		idx.y = (game->keycode == KEY_UP) ? 0 : game->array_size - 1;
		iterator.x = 0;
		idx.x = line_count;
	}
	else
	{
		iterator.x = (game->keycode == KEY_LEFT) ? 1 : -1;
		idx.x = (game->keycode == KEY_LEFT) ? 0 : game->array_size - 1;
		iterator.y = 0;
		idx.y = line_count;
	}
	idx_line = 0;
	while (idx_line < game->array_size)
	{
		set_number(game, &(game->line[idx_line]), &(game->game_array[idx.y][idx.x]), set_type);
		//game->line[idx_line] = game->game_array[idx.y][idx.x];
		idx.y += iterator.y;
		idx.x += iterator.x;
		idx_line++;
	}
}

void	set_number(t_game_data *game, int *line_num, int *array_num, int set_type)
{
	if (*line_num != *array_num)
	{
		if (set_type == SET_TO_ARRAY)
			game->player_moved = TRUE;
		if (game->checking_mode == TRUE)
			return;
		if (set_type == SET_TO_LINE)
			*line_num = *array_num;
		else if (set_type == SET_TO_ARRAY)
			*array_num = *line_num;
	}
}
