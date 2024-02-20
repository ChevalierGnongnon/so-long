/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:24 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/20 17:26:32 by chhoflac         ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	char		**map;
	char		*path;
	int			fd;
	t_elements	count;

	if (argc == 2)
	{
		path = argv[1];
		fd = open(path, O_RDONLY);
		map = ft_stock_map(fd);
		count = ft_set_struct(map);
		ft_display_info(map, count, path);
		close(fd);
	}
}
