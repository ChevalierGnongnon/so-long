/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:58:06 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/20 15:33:20 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_bordlines(char *line)
{
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_midlines(char *line)
{
	size_t	size;

	size = 0;
	while (line[size] != '\n')
		size++;
	if (line[0] != '1' && line[size - 3] != '1')
		return (0);
	return (1);
}

int	ft_check_equal(char **map)
{
	int	i;

	i = 1;
	while (map[i - 1])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[i - 1]))
			return (0);
		i++;
	}
	if (ft_strlen(map[i] + 1) != ft_strlen(map[i - 1]))
		return (0);	
	return (1);
}

/*int	ft_check_shape(char **map)
{

}*/
