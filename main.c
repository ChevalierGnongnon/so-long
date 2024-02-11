/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:47:24 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/11 14:34:17 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*map_path;

	fd = 0;
	if (argc == 2)
	{
		map_path = &argv[1][1]; 
		fd = open(map_path, O_RDONLY);
		if(fd)
			printf("%s", map_path);
	}
	close(fd);
}
