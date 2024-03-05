/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:24 by chhoflac          #+#    #+#             */
/*   Updated: 2024/03/05 19:06:02 by chhoflac         ###   ########.fr       */
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

void keyboard_hook(mlx_key_data_t key_entered, void *param)
{
	ft_printf("%p", param);
	if (key_entered.key == MLX_KEY_LEFT
		&& key_entered.action == MLX_PRESS)
	{
		ft_printf("gauche\n");
	}
	if (key_entered.key == MLX_KEY_RIGHT
		&& key_entered.action == MLX_PRESS)
	{
		ft_printf("droite\n");
	}
	if (key_entered.key == MLX_KEY_UP
		&& key_entered.action == MLX_PRESS)
	{
		ft_printf("haut\n");
	}
	if (key_entered.key == MLX_KEY_DOWN
		&& key_entered.action == MLX_PRESS)
	{
		ft_printf("bas\n");
	}
}

int	main(void)
{
	mlx_t *mlx;

	if (!(mlx = mlx_init(720, 480, "MLX42", true)))
		return (EXIT_FAILURE);

	mlx_key_hook(mlx, &keyboard_hook, NULL);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
