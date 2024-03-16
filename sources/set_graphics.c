/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:28:15 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/16 19:55:20 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_graphics	ft_graphics_set(t_game *game)
{
	t_graphics	g;

	g.ground = ft_background(game->map, game->mlx);
	ft_img_stock(game->mlx, &g);
	ft_display_elements(game->map, game->mlx, &g);
	return (g);
}

void	clean_graphics(mlx_t *mlx, t_graphics g)
{
	mlx_delete_image(mlx, g.ground);
	ft_clean_img(mlx, g.sup);
}
