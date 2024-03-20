/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   character.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 09:46:58 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/20 10:13:24 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_character_stock(mlx_t *mlx, t_graphics *graphics)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("images/pld_1.png");
	graphics->sup[0] = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("images/pll_1.png");
	graphics->sup[1] = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("images/plr_1.png");
	graphics->sup[2] = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("images/plu_1.png");
	graphics->sup[3] = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
}
