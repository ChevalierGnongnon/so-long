/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:47:59 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/27 16:14:01 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_setting(t_elements cnt1, int fd, t_game *game)
{
	char		**map;
	char		**flooded_map;
	t_elements	cnt2;

	if (fd < 1)
		return (ft_putstr_fd("Error\nwrong fd", 2), NULL);
	map = ft_stock_map(fd);
	if (!map)
		return (ft_putstr_fd("Error\nmap have holes", 2), NULL);
	if (!ft_check_shape(map) || !ft_check_forbidden_char(map))
		return (ft_putstr_fd("Error\nwrong shape or forbidden char", 2), \
		ft_clear(map), NULL);
	cnt1 = ft_set_struct(map);
	game->collectibles = cnt1.collectibles;
	if (!ft_check_elements(cnt1))
		return (ft_putstr_fd("Error\nno enough elements", 2), ft_clear(map) \
		, NULL);
	cnt2 = ft_set_cnt();
	flooded_map = ft_mapcopy(map);
	ft_start_flood(flooded_map, &cnt2);
	ft_clear(flooded_map);
	if (!ft_compare(cnt1, cnt2))
		return (ft_putstr_fd("Error\ncan't reach all elements", 2), \
		ft_clear(map), NULL);
	return (map);
}
