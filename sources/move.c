/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:19:19 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/12 23:44:52 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyboard_hook_count(mlx_key_data_t key_entered, void *param)
{
	static int	nb_moves = 0;

	if (key_entered.key == MLX_KEY_A
		&& key_entered.action == MLX_PRESS)
		ft_move_character
	else if (key_entered.key == MLX_KEY_D
		&& key_entered.action == MLX_PRESS)
		ft_printf("droite\n");
	else if (key_entered.key == MLX_KEY_W
		&& key_entered.action == MLX_PRESS)
		ft_printf("haut\n");
	else if (key_entered.key == MLX_KEY_S
		&& key_entered.action == MLX_PRESS)
		ft_printf("bas\n");
	else if (key_entered.key == MLX_KEY_ESCAPE
		&& key_entered.action == MLX_PRESS)
		mlx_close_window(param);
	else if (key_entered.action == MLX_PRESS)
	{
		nb_moves++;
		ft_printf("moves : %d\n", nb_moves);
	}
}

void ft_move_character(mlx_t mlx, t_pos base, t_pos new)
{

}
  