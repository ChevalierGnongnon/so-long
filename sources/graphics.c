/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:27:54 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/16 22:17:14 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*ft_background(char **map, mlx_t *mlx)
{
	int					x;
	int					y;
	mlx_texture_t		*ground;
	mlx_image_t			*img;

	ground = mlx_load_png("images/ground.png");
	if (!ground)
		exit(EXIT_FAILURE);
	img = mlx_texture_to_image(mlx, ground);
	x = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			mlx_image_to_window(mlx, img, x * 32, y * 32);
			x++;
		}
		y++;
	}
	mlx_delete_texture(ground);
	return (img);
}

mlx_image_t	**ft_img_stock(mlx_t *mlx, t_graphics *graphics)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("images/pld_1.png");
	graphics->sup[0] = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("images/chest.png");
	graphics->sup[1] = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("images/stump.png");
	graphics->sup[2] = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("images/flower.png");
	graphics->sup[3] = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	return (graphics->sup);
}

void	ft_select(char c, mlx_t *mlx, mlx_image_t **stock, t_pos pos)
{
	if (c == '1')
		mlx_image_to_window(mlx, stock[2], pos.x * 32, pos.y * 32);
	else if (c == 'P')
		mlx_image_to_window(mlx, stock[0], pos.x * 32, pos.y * 32);
	else if (c == 'C')
		mlx_image_to_window(mlx, stock[3], pos.x * 32, pos.y * 32);
	else if (c == 'E')
		mlx_image_to_window(mlx, stock[1], pos.x * 32, pos.y * 32);
}

void	ft_clean_img(mlx_t *mlx, mlx_image_t **stock)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_delete_image(mlx, stock[i]);
		i++;
	}
}

void	ft_display_elements(char **map, mlx_t *mlx, t_graphics *graphics)
{
	t_pos		pos;

	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
		{
			if (map[pos.y][pos.x] != '0')
				ft_select(map[pos.y][pos.x], mlx, graphics->sup, pos);
			pos.x++;
		}
		pos.y++;
	}
}
