/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:37:26 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/16 14:56:10 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_reach_elements(char **map, t_pos pos, t_elements elements)
{
	if (map[pos.x][pos.y] == 'C')
		elements.collectibles--;
	if (elements.collectibles == 0)
		acti
}

void	ft_reach_end(void)
{

}

