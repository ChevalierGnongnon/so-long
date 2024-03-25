/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:24 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/25 15:43:15 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_extension(char *f)
{
	int		sze;

	sze = ft_strlen(f);
	if ((sze >= 5) && (f[sze - 1] == 'r' && f[sze - 2] == 'e'
			&& f[sze - 3] == 'b' && f[sze - 4] == '.'))
		return (1);
	else
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

void	find_player(t_game *game)
{
	int	px;
	int	py;

	py = 0;
	while (game->map[py])
	{
		px = 0;
		while (game->map[py][px])
		{
			if (game->map[py][px] == 'P')
			{
				game->pos_player.x = px;
				game->pos_player.y = py;
				return ;
			}
			px++;
		}
		py++;
	}
}

char	**ft_setting(t_elements cnt1, int fd, t_game *game)
{
	char		**map;
	char		**flooded_map;
	t_elements	cnt2;

	if (fd < 1)
		return (ft_putstr_fd("wrong fd", 2), NULL);
	map = ft_stock_map(fd);
	if (!ft_check_shape(map) || !ft_check_forbidden_char(map))
		return (ft_putstr_fd("wrong shape or forbidden char", 2), NULL);
	cnt1 = ft_set_struct(map);
	game->collectibles = cnt1.collectibles;
	if (!ft_check_elements(cnt1))
		return (ft_putstr_fd("no enough elements", 2), NULL);
	cnt2 = ft_set_cnt();
	flooded_map = ft_mapcopy(map);
	ft_start_flood(flooded_map, &cnt2);
	if (!ft_compare(cnt1, cnt2))
		return (ft_putstr_fd("Error :\ncan't reach all elements", 2), NULL);
	return (map);
}

int	main(int argc, char **argv)
{
	t_game		game;
	t_elements	c1;

	if (argc == 2)
	{
		c1 = ft_set_cnt();
		if (ft_check_extension(argv[1]))
		{
			game.fd = open(argv[1], O_RDONLY);
			game.map = ft_setting(c1, game.fd, &game);
			game.mlx = mlx_init(300, 300, "so long", true);
			if (!game.map)
				return (EXIT_FAILURE);
			find_player(&game);
			if (!game.mlx)
				exit(EXIT_FAILURE);
			game.graphics.ground = NULL;
			ft_graphics_set(&game);
			mlx_key_hook(game.mlx, &keyboard_hook_count, &game);
			mlx_loop(game.mlx);
			clean_graphics(game.mlx, game.graphics);
			close(game.fd);
			return (EXIT_SUCCESS);
		}
	}
}