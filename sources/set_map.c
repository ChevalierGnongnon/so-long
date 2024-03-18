/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:48:00 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/18 16:54:52 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_elements	ft_set_cnt(void)
{
	t_elements	cnt2;

	cnt2.exit = 0;
	cnt2.collectibles = 0;
	cnt2.start = 0;
	return (cnt2);
}

char	**ft_mapalloc(char **origin)
{
	int		i;
	int		j;
	int		k;
	char	**copy;

	i = 0;
	j = 0;
	k = 0;
	while (origin[i])
		i++;
	while (origin[0][j])
		j++;
	copy = ft_calloc(sizeof(char **), i + 1);
	if (!copy)
		return (ft_clear(copy), NULL);
	while (origin[k])
	{
		copy[k] = ft_calloc(sizeof(char *), j + 1);
		if (!copy[k])
			return (ft_clear(copy), NULL);
		k++;
	}
	return (copy);
}

char	**ft_mapcopy(char **map)
{
	char	**copy;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	copy = ft_mapalloc(map);
	if (!copy)
		return (NULL);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			copy[i][j] = map[i][j];
			j++;
		}
		i++;
	}
	return (copy);
}
