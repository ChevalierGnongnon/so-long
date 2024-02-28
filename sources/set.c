/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:48:00 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/28 16:56:22 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_elements ft_set_cnt(void)
{
	t_elements cnt2;

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

char	**ft_setting(t_elements cnt1, int fd)
{
	char		**map;
	char		**flooded_map;
	t_elements	cnt2;

	if (fd < 1)
		return (ft_putstr_fd("wrong fd", 2),NULL);
	map = ft_stock_map(fd);
	if (!ft_check_shape(map) || !ft_check_forbidden_char(map))
		return (ft_putstr_fd("wrong shape or forbidden char", 2),NULL);
	cnt1 = ft_set_struct(map);
	if (!ft_check_elements(cnt1))
		return (ft_putstr_fd("no enough elements", 2), NULL);
	cnt2 = ft_set_cnt();
	flooded_map = ft_mapcopy(map);
	ft_start_flood(flooded_map, &cnt2);
	if (!ft_compare(cnt1, cnt2))
		return (ft_putstr_fd("can't reach all elements", 2), NULL);
	return (map);
}
