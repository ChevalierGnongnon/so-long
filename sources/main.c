/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:24 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/17 13:35:52 by chhoflac         ###   ########.fr       */
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

void	ft_display_info(t_elements count/*int fd*/)
{
	//Get numbers of collectibles
	ft_printf("player : %d\n", count.start);
	ft_printf("collectibles : %d\n", count.collectibles);
	ft_printf("exit : %d\n", count.exit);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		*map_path;
	t_elements	count;
	char 		**map;
	int			i;

	i =0;
	fd = 0;
	map_path = argv[1];
	if (argc == 2)
	{
		fd = open(map_path, O_RDONLY);
		count = ft_set_struct(fd);
		map = ft_stock_map(fd);
		while(map[i])
		{
			ft_printf(map[i]);
			i++;
		}		
		close(fd);
	}
}

//delete it, only for getting infos
