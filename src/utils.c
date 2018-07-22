/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:40:06 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/22 16:46:53 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_printf.h"
#include "../include/game_2048.h"
#include <ncurses.h>
#include <stdlib.h>

void	error_exit(int error_name, t_data *game)
{
	(void)game;
	if (error_name == BAD_WIN_VALUE)
		printw("WIN_VALUE = %d is not power of 2. You cannot run the game!\n", WIN_VALUE);
	else if (error_name == TO_SMALL_WINDOW)
	{
		printw("Window too small. Exiting.");
	}
	exit(1);
}

void	ft_error(const char *message, int exit_code)
{
	endwin();
	ft_printf("%s\n", message);
	exit(exit_code);
}

void	check_win_value(t_winv win_value)
{
	while (win_value > 1)
	{
		if (win_value % 2 != 0)
			break ;
		win_value /= 2;
	}
	if (win_value > 1)
		error_exit(BAD_WIN_VALUE, NULL);
}

unsigned	numlen(unsigned num)
{
	unsigned i;

	i = 1;
	while (num /= 10)
		++i;
	return (i);
}
