/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_graphics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:28:15 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/12 21:55:47 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_graphics	ft_graphics_set(mlx_t *mlx, int fd)
{
	char		**map;
	t_graphics	g;

	map = ft_stock_map(fd);
	g.ground = ft_background(map, mlx);
	ft_img_stock(mlx, &g);
	ft_display_elements(map, mlx, &g);
	return (g);
}

void	clean_graphics(mlx_t *mlx, t_graphics g)
{
	mlx_delete_image(mlx, g.ground);
	ft_clean_img(mlx, g.sup);
}