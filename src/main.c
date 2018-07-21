/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:14:50 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/21 16:02:57 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "2048.h"

int		main(void)
{
	t_data	game;

	ft_bzero(&game, sizeof(game));
	initialize(&game);
	while (42)
	{
		update(&game);
	}
	return (0);
}
