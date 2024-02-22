/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:27:54 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/22 10:44:43 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_display_info(char **map, t_elements count, t_elements count2, char *path)
{
	int	i, j;

	j = 0;
	i = 0;
	ft_printf("%s", path);
	ft_printf("\n----------\n");
	while (map[i])
	{
		ft_printf("%s", map[i]);
		write(1, "\n", 1);
		i++;
	}
	ft_printf("----------\n");
	i = 0;
	while (map[i])
	{
		ft_printf("%d\n", ft_strlen(map[i]));
		i++;
	}
	ft_printf("----------\n");
	ft_printf("player : %d\n", count.start);
	ft_printf("collectibles : %d\n", count.collectibles);
	ft_printf("exit : %d", count.exit);
	ft_printf("\n----------\n");
	if (ft_check_shape(map))
		ft_printf("SHAPE ok\n");
	else if (!ft_check_shape(map))
		ft_printf("SHAPE not ok\n");
	ft_printf("\n----------\n");
	while (map[j])
	{
		ft_printf("%s", map[j]);
		write(1, "\n", 1);
		j++;
	}

	ft_printf("player : %d\n", count2.start);
	ft_printf("collectibles : %d\n", count2.collectibles);
	ft_printf("exit : %d", count2.exit);
}
