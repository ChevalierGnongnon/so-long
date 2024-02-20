/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:27:54 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/20 17:57:38 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_display_info(char **map, t_elements count, char *path)
{
	int	i;

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
		ft_printf("SHAPE ok");
	else if (!ft_check_shape(map))
		ft_printf("SHAPE not ok");
}
