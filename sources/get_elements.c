/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:10:03 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/21 16:40:42 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_elements(char *line, t_elements *elements)
{
	size_t		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			elements->start++;
		else if (line[i] == 'C')
			elements->collectibles++;
		else if (line[i] == 'E')
			elements->exit++;
		i++;
	}
}

t_elements	ft_set_struct(char **map)
{
	t_elements	elements;
	size_t		i;

	i = 0;
	elements.collectibles = 0;
	elements.exit = 0;
	elements.start = 0;
	while (map[i])
	{
		ft_get_elements(map[i], &elements);
		i++;
	}
	return (elements);
}

/*int	ft_check_elements(t_elements count)
{
	if (count.collectibles >= 1 && count.start == 1 && count.exit == 1)
		return (1);
	else if (count.collectibles == 0)
		return (0);
	else if (count.start > 1)
		return (0);
	else if (count.exit > 1)
		return (0);
}*/
