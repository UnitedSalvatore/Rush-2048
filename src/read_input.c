/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 15:28:01 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/22 18:30:00 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/game_2048.h"
#include <ncurses.h>

void	read_input(t_data *game)
{
	unsigned ch;

	ch = getch();
	if (ch == '1' || ch == KEY_DOWN || ch == KEY_UP ||
			ch == KEY_LEFT || ch == KEY_RIGHT || ch == ESC)
		game->ch = ch;
}
