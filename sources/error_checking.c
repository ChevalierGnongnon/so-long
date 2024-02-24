/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:48:00 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/24 17:36:37 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_display_error(t_elements cnt, t_elements cnt2, int fd)
{
	if (!ft_check_elements(cnt))
		return (0);
	if (!ft_compare(cnt, cnt2))
		return (0);
	if (fd < 1)
	{
		ft_putstr_fd("Error :\nWrong file directory", 2);
		return(0);
	}
}
