/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:28:15 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/16 22:16:51 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_graphics_set(t_game *game)
{
	if (game->graphics.ground) {
		mlx_delete_image(game->mlx, game->graphics.ground);
		ft_clean_img(game->mlx, game->graphics.sup);
	}
	game->graphics.ground = ft_background(game->map, game->mlx);
	ft_img_stock(game->mlx, &(game->graphics));
	ft_display_elements(game->map, game->mlx, &(game->graphics));
}

void	clean_graphics(mlx_t *mlx, t_graphics g)
{
	mlx_delete_image(mlx, g.ground);
	ft_clean_img(mlx, g.sup);
}
