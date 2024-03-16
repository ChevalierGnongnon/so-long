/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:37:26 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/16 17:24:14 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_collect(t_elements elements)
{
	static int exit_available;

	elements.collectibles--;
	if (elements.collectibles == 0)
		exit_available = 1;
	return (exit_available);
}

/*void	ft_reach_end(char **map, t_pos pos, t_elements *elements)
{
	if (elements->collectibles == 0)
	{
		ft_printf("Congratulations, you've reach all collectibles !");
		quit();
	}
}*/

