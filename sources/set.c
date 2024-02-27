/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:48:00 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/27 11:31:25 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_setting(char *path, t_elements cnt1, t_elements cnt2)
{
	int		fd;
	char	**map;
	char	**flooded_map;

	if (!ft_check_extension(path))
		return (0);
	fd = open(path, O_RDONLY);
	if (fd < 1)
		return (0);
	map = ft_stock_map(fd);
	if (!ft_check_shape(map) || !ft_check_forbidden_char(map))
		return (0);
	cnt1 = ft_set_struct(map);
	if (ft_check_elements(cnt1))
		return (0);
	flooded_map = ft_stock_map(fd);
	ft_start_flood(flooded_map, cnt2);
	if (!ft_compare(cnt1, cnt2))
		return (0);
	close(fd);
	return (1);
}

