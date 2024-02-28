/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:08:14 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/28 15:57:33 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int isaccessible(t_elements *count2, char element)
{
	if (element == '1' || element == '2')
		return (0);
	else if (element == 'E')
		count2->exit++;
	else if (element == 'C')
		count2->collectibles++;
	else if (element == 'P')
		count2->start++;
	return (1);
}

void	ft_flood(char **map, int stx, int sty, t_elements *count2)
{
	if (map[stx] && map[stx][sty] && isaccessible(count2, map[stx][sty]))
	{
		map[stx][sty] = '2';
		ft_flood(map, stx + 1, sty, count2);
		ft_flood(map, stx, sty + 1, count2);
		ft_flood(map, stx - 1, sty, count2);
		ft_flood(map, stx, sty - 1, count2);
	}
	else
		return ;
}

void	ft_start_flood(char **map, t_elements *count2)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				ft_flood(map, i, j, count2);
			j++;
		}
		i++;
	}
}