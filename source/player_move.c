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
	if (handle_player_move(game, game->keycode) == TRUE)
		return (TRUE);
	else
		return (FALSE);
}

void	player_press_key(t_game_data *game)
{
	int		key;

	while (TRUE)
	{
		key = getch();
		if (key == KEY_DOWN || key == KEY_UP ||
			key == KEY_LEFT || key == KEY_RIGHT)
			break ;
		if (key == ESC)
			break ;
	}
	game->keycode = key;
}

int		handle_player_move(t_game_data *game, int keycode)
{
	int		line_count;

	if (keycode == ESC)
		return (FALSE);
	else
	{
		game->player_moved = FALSE;
		line_count = 0;
		game->num_of_free_cell = 0;
		while (line_count < game->array_size)
		{
			fill_line(game, line_count, SET_TO_LINE, keycode);
			handle_line(game);
			fill_line(game, line_count, SET_TO_ARRAY, keycode);
			line_count++;
		}
		return (TRUE);
	}
}

void	fill_line(t_game_data *game, int line_count, int set_type, int keycode)
{
	t_position	idx;
	t_position	iterator;
	int			idx_line;

	if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		iterator.y = (keycode == KEY_UP) ? 1 : -1;
		idx.y = (keycode == KEY_UP) ? 0 : game->array_size - 1;
		iterator.x = 0;
		idx.x = line_count;
	}
	else
	{
		iterator.x = (keycode == KEY_LEFT) ? 1 : -1;
		idx.x = (keycode == KEY_LEFT) ? 0 : game->array_size - 1;
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
		{
			game->player_moved = TRUE;
		}

		if (game->checking_mode == TRUE)
			return;
		if (set_type == SET_TO_LINE)
			*line_num = *array_num;
		else if (set_type == SET_TO_ARRAY)
			*array_num = *line_num;
	}
}


/*
 *
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
			nodelay(stdscr, FALSE);
			if (second_key == -1)
				break ;
		}
	}
	game->keycode = first_key;
}
 *
 */