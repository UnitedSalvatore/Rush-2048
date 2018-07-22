/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:40:06 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/22 11:30:53 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_printf.h"
#include <ncurses.h>
#include <stdlib.h>

void	ft_error(const char *message, int exit_code)
{
	endwin();
	ft_printf("%s\n", message);
	exit(exit_code);
}
