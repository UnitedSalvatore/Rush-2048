/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypikul <ypikul@student.42.unit.ua>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:14:50 by ypikul            #+#    #+#             */
/*   Updated: 2018/07/22 11:41:40 by ypikul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"
#include "../include/2048.h"

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
