/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:19:19 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/16 22:20:08 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *game)
{
	game->pos_player.y -= 1;
	game->map[game->pos_player.y + 1][game->pos_player.x] = '0';
	game->map[game->pos_player.y][game->pos_player.x] = 'P';
	ft_graphics_set(game);
}

static void	move_down(t_game *game)
{
	game->pos_player.y += 1;
	game->map[game->pos_player.y - 1][game->pos_player.x] = '0';
	game->map[game->pos_player.y][game->pos_player.x] = 'P';
	ft_graphics_set(game);
}

static void	move_left(t_game *game)
{
	game->pos_player.x -= 1;
	game->map[game->pos_player.y][game->pos_player.x + 1] = '0';
	game->map[game->pos_player.y][game->pos_player.x] = 'P';
	ft_graphics_set(game);
}

static void	move_right(t_game *game)
{
	game->pos_player.x += 1;
	game->map[game->pos_player.y][game->pos_player.x - 1] = '0';
	game->map[game->pos_player.y][game->pos_player.x] = 'P';
	ft_graphics_set(game);
}

void	keyboard_hook_count(mlx_key_data_t key_entered, void *game)
{
	static int	nb_moves = 0;

	if (key_entered.key == MLX_KEY_A
		&& key_entered.action == MLX_PRESS)
		move_left((t_game *) game);
	else if (key_entered.key == MLX_KEY_D
		&& key_entered.action == MLX_PRESS)
		move_right((t_game *) game);
	else if (key_entered.key == MLX_KEY_W
		&& key_entered.action == MLX_PRESS)
		move_up((t_game *) game);
	else if (key_entered.key == MLX_KEY_S
		&& key_entered.action == MLX_PRESS)
		move_down((t_game *) game);
	else if (key_entered.action == MLX_PRESS)
	{
		nb_moves++;
		ft_printf("moves : %d\n", nb_moves);
	}
}
