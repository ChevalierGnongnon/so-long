/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:19:19 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/11 00:57:24 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyboard_hook_count(mlx_key_data_t key_entered, void *param)
{
	static int	nb_moves = 0;

	if (key_entered.key == MLX_KEY_LEFT
		&& key_entered.action == MLX_PRESS)
		ft_printf("gauche\n");
	if (key_entered.key == MLX_KEY_RIGHT
		&& key_entered.action == MLX_PRESS)
		ft_printf("droite\n");
	if (key_entered.key == MLX_KEY_UP
		&& key_entered.action == MLX_PRESS)
		ft_printf("haut\n");
	if (key_entered.key == MLX_KEY_DOWN
		&& key_entered.action == MLX_PRESS)
		ft_printf("bas\n");
	if (key_entered.key == MLX_KEY_ESCAPE
		&& key_entered.action == MLX_PRESS)
		mlx_close_window(param);
	else if (key_entered.action == MLX_PRESS)
	{
		nb_moves++;
		ft_printf("moves : %d\n", nb_moves);
	}
}
