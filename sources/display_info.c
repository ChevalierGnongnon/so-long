/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:27:54 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/09 16:23:57 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*ft_background(char **map, mlx_t *mlx)
{
	int				x;
	int				y;
	mlx_image_t		img;
	
	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			img = ft_display_img(&map[y]);
			x++;
		}
		y++;
	}
	return (img);
}

mlx_image_t *ft_display_img(char c)
{
	mlx_texture_t *texture;

	if (c == '1')
		texture = mlx_load_png("images/stump.png");
	else if (c == 'P')
		texture = mlx_load_png("images/pld_1.png");
	else if (c == 'C')
		texture = mlx_load_png("images/flower.png");
	else if (c == 'E')
		texture = mlx_load_png("images/chest.png")
}
