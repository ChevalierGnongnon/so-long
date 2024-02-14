/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:10:03 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/14 14:07:34 by chhoflac         ###   ########.fr       */
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

t_elements	ft_set_struct(int fd)
{
	char		*line;
	t_elements	elements;

	line = get_next_line(fd);
	elements.collectibles = 0;
	elements.exit = 0;
	elements.start = 0;
	while (line)
	{
		ft_get_elements(line, &elements);
		free(line);
		line = get_next_line(fd);
	}
	return (elements);
}




