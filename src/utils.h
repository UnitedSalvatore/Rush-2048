/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 15:40:06 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/21 15:47:38 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_printf.h"
#include <ncurses.h>

void	ft_error(const char *message, int exit_code)
{
	endwin();
	ft_printf("%s\n", message);
	exit(exit_code);
}
