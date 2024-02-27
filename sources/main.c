/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:24 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/27 15:38:16 by chhoflac         ###   ########.fr       */
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
	ft_putstr_fd("Error :\n Wrong extension, please use .ber files", 2);
	return (0);
}

int	ft_compare(t_elements cnt, t_elements cnt2)
{
	if (cnt.collectibles != cnt2.collectibles || cnt.start != cnt2.start
		|| cnt.exit != cnt2.exit)
	{
		ft_putstr_fd("Error :\n Impossible to access all items on map", 2);
		return (0);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_elements cnt1;
	int fd;
	char **map;

	if (argc == 2)
	{
		cnt1.collectibles = 0;
		cnt1.start = 0;
		cnt1.exit = 0;
		if (!ft_check_extension(argv[1]))
			ft_putstr_fd("Error\nWrong extension", 2);
		fd = open(argv[1], O_RDONLY);
		map = ft_setting(cnt1, fd);
		if (!map)
			ft_putstr_fd("Error\n", 2);
		else
			ft_printf("map setting ok");
		close(fd);
	}
}
