/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:19:19 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/27 14:47:04 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_move(t_game *game, int pos_x, int pos_y)
{
	return ((game->map[pos_y][pos_x] != '1' && game->map[pos_y][pos_x] != 'E') \
		|| (game->map[pos_y][pos_x] == 'E' && game->collectibles == 0));
}

static void	move(t_game *game, int *moves, int off_x, int off_y)
{
	if (!can_move(game, game->pos_player.x + off_x, game->pos_player.y + off_y))
		return ;
	game->pos_player.y += off_y;
	game->pos_player.x += off_x;
	if (game->map[game->pos_player.y][game->pos_player.x] == 'C')
		game->collectibles--;
	if (game->map[game->pos_player.y][game->pos_player.x] == 'E'
		&& game->collectibles == 0)
	{
		mlx_close_window(game->mlx);
		ft_printf("Congrats you won !!!!\nMoves : %d", *moves);
		return ;
	}
	game->map[game->pos_player.y - off_y][game->pos_player.x - off_x] = '0';
	game->map[game->pos_player.y][game->pos_player.x] = 'P';
	ft_graphics_set(game);
	(*moves)++;
	ft_printf("Moves : %d Collectibles : %d\n", *moves, game->collectibles);
}

void	keyboard_hook_count(mlx_key_data_t key_entered, void *game)
{
	static int	nb_moves = 0;

	if (key_entered.key == MLX_KEY_A
		&& key_entered.action == MLX_PRESS)
		move(game, &nb_moves, -1, 0);
	else if (key_entered.key == MLX_KEY_D
		&& key_entered.action == MLX_PRESS)
		move(game, &nb_moves, +1, 0);
	else if (key_entered.key == MLX_KEY_W
		&& key_entered.action == MLX_PRESS)
		move(game, &nb_moves, 0, -1);
	else if (key_entered.key == MLX_KEY_S
		&& key_entered.action == MLX_PRESS)
		move(game, &nb_moves, 0, +1);
	if (key_entered.key == MLX_KEY_ESCAPE
		&& key_entered.action == MLX_PRESS)
	{
		mlx_close_window(((t_game *) game)->mlx);
		return ;
	}
}
