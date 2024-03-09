/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:24 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/09 15:20:20 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_check_extension(char *f)
{
	int		sze;

	sze = ft_strlen(f);
	if ((sze >= 5) && (f[sze - 1] == 'r' && f[sze - 2] == 'e'
			&& f[sze - 3] == 'b' && f[sze - 4] == '.'))
		return (1);
	ft_putstr_fd("Error :\n Wrong extension, please use .ber files", 2);
	return (0);
}

int	ft_compare(t_elements cnt, t_elements cnt2)
{
	if (cnt.collectibles != cnt2.collectibles || cnt.start != cnt2.start
		|| cnt.exit != cnt2.exit)
	{
		ft_putstr_fd("Error :\n Impossible to access all items on map", 2);
		return (0);
	}
	return (1);
}

int main(void)
{
	mlx_t	*mlx;
	char	**map;
	int		fd;
	mlx_image_t *ground;

	fd = open("maps/map_ok2.ber", O_RDONLY);
	mlx = mlx_init(128, 128, "test", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	map = ft_stock_map(fd);
	ground = ft_background(map, mlx);
	mlx_loop(mlx);
	mlx_delete_image(mlx, ground);
	close(fd);
	return (EXIT_SUCCESS);
}

/*int	main(void)
{
	mlx_t *mlx;

	mlx = mlx_init(720, 480, "MLX42", true);
	if (!mlx)
		return (EXIT_FAILURE);
	ft_mlx_set(mlx);
	return (EXIT_SUCCESS);
}*/
