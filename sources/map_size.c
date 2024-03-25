/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:53:00 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/25 17:06:49 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_map_size_check(t_game *game)
{
	int	x;
	int	y;
	int	area;

	x = 0;
	y = 0;
	while (game->map[0][x])
		x++;
	while (game->map[y])
		y++;
	area = x * y;
	if (area > 4000)
		return (0);
	else
	{
		game->s_x = x;
		game->s_y = y;
	}
	return (1);
}