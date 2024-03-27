/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:24 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/27 15:10:48 by chhoflac         ###   ########.fr       */
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
		ft_putstr_fd("Error\nWrong extension, please use .ber files", 2);
	return (0);
}

int	ft_compare(t_elements cnt, t_elements cnt2)
{
	if (cnt.collectibles != cnt2.collectibles || cnt.start != cnt2.start
		|| cnt.exit != cnt2.exit)
		return (0);
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

static
int	launch(t_game *game)
{
	game->mlx = mlx_init((game->s_x * 32) + 1, \
		(game->s_y * 32) + 1, "test", true);
	find_player(game);
	if (!game->mlx)
		return (EXIT_FAILURE);
	game->graphics.ground = NULL;
	ft_graphics_set(game);
	mlx_key_hook(game->mlx, &keyboard_hook_count, game);
	mlx_loop(game->mlx);
	clean_graphics(game->mlx, game->graphics);
	mlx_terminate(game->mlx);
	close(game->fd);
	ft_clear(game->map);
	return (EXIT_SUCCESS);
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
			if (!game.map)
				return (EXIT_FAILURE);
			if (!ft_map_size_check(&game))
			{
				ft_clear(game.map);
				ft_putstr_fd("Error\nmap too big", 2);
				return (EXIT_FAILURE);
			}
			return (launch(&game));
		}
	}
}
