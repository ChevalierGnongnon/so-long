/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_inputs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:19:19 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/05 22:45:25 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keyboard_hook(mlx_key_data_t key_entered, void *param, t_param par)
{
	ft_printf("%p", param);
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
	par.nb_moves++;
	ft_printf("moves : %d", par.nb_moves);
}
