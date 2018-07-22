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

int		check_win_value(void)
{
	int		win_value;

	win_value = WIN_VALUE;
	while (win_value > 1)
	{
		if (win_value % 2 != 0)
			break ;
		win_value /= 2;
	}
	if (win_value > 1)
		error_exit(BAD_WIN_VALUE, NULL);
	return (TRUE);
}
