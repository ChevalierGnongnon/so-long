/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:23:41 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/18 15:42:45 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_display_moves(mlx_key_data_t key_entered, int *moves)
{	
	if (key_entered.action == MLX_PRESS && (key_entered.key == MLX_KEY_A \
		|| key_entered.key == MLX_KEY_W || key_entered.key == MLX_KEY_S \
		|| key_entered.key == MLX_KEY_D))
	{
		(*moves)++;
		ft_printf("moves : %d\n", *moves);
	}
}

