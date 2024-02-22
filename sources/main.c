/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:24 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/22 10:49:27 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//delete it 
//void	ft_display_info(t_elements count, int fd);

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
		ft_start_flood(map, &count2);
		ft_display_info(map, count, count2, path);
		if (ft_compare(count, count2))
			ft_printf("path ok\n");
		else
			ft_printf("path not ok\n");
		close(fd);
	}
}
