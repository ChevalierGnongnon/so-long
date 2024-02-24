/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:24 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/24 12:25:48 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_check_extension(char *f)
{
	int		sze;

	sze = ft_strlen(f);
	if ((sze >= 5) && (f[sze - 1] == 'r' && f[sze - 2] == 'e'
			&& f[sze - 3] == 'b' && f[sze - 4] == '.'))
		return (1);
	return (0);
}

int	ft_compare(t_elements count, t_elements count2)
{
	if (count.collectibles != count2.collectibles)
		return (0);
	if (count.start != count2.start)
		return (0);
	if (count.exit != count2.exit)
		return (0);
	return (1);
}

int		main(int argc, char **argv)
{
	char		**map;
	char		*path;
	int			fd;
	t_elements	count;
	t_elements	count2;

	count2.start = 0;
	count2.exit = 0;
	count2.collectibles = 0;
	if (argc == 2)
	{
		path = argv[1];
		fd = open(path, O_RDONLY);
		map = ft_stock_map(fd);
		count = ft_set_struct(map);
		if (ft_check_forbidden_char(map))
			ft_printf("map char ok");
		else
			ft_printf("map char not ok");
		ft_start_flood(map, &count2);
		display_info(map, count, count2, path);
	
		close(fd);
	}
}
