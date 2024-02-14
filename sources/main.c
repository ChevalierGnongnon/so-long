/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:24 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/14 10:29:38 by chhoflac         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	int			fd;
	char		*map_path;
	t_elements	count;

	fd = 0;
	map_path = argv[1];
	if (argc == 2)
	{
		fd = open(map_path, O_RDONLY);
		count = ft_map_check(fd);
		ft_printf("player : %d\ncollectibles : %d\nexit : %d\n", count.start, count.collectibles, count.exit);
		close(fd);
	}
}
