/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:24 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/16 20:16:21 by chhoflac         ###   ########.fr       */
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
	px = 0;
	while (game->map[py])
	{
		while (game->map[py][px])
		{
			if (game->map[py][px] == 'P')
			{
				game->pos_player->x = px;
				game->pos_player->y = py;
				break ;
			}
			px++;
		}
		py++;
	}
}

int	main(int argc, char **argv)
{
	t_graphics	g;
	t_game		game;

	if (argc == 2)
	{
		game.fd = open(argv[1], O_RDONLY);
		game.mlx = mlx_init(300, 300, "test", true);
		game.map = ft_stock_map(game.fd);
		find_player(&game);
		if (!game.mlx)
			exit(EXIT_FAILURE);
		g = ft_graphics_set(&game);
		mlx_key_hook(game.mlx, &keyboard_hook_count, &game);
		mlx_loop(game.mlx);
		clean_graphics(game.mlx, g);
		close(game.fd);
		return (EXIT_SUCCESS);
	}
}