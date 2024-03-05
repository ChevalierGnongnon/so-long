/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_activate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 23:55:41 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/06 00:07:34 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_mlx_set(mlx_t *mlx)
{
	mlx_key_hook(mlx, &keyboard_hook_count, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}