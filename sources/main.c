/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:24 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/19 15:14:46 by chhoflac         ###   ########.fr       */
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

void	ft_display_info(char **map, t_elements count)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("\n----------\n");
	ft_printf("player : %d\n", count.start);
	ft_printf("collectibles : %d\n", count.collectibles);
	ft_printf("exit : %d\n", count.exit);
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
		ft_printf("%s\n", path);
		fd = open(path, O_RDONLY);
		map = ft_stock_map(fd);
		count = ft_set_struct(map);
		ft_display_info(map, count);
		close(fd);
	}
}
