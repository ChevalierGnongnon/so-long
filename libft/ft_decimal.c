/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 10:20:32 by chhoflac          #+#    #+#             */
/*   Updated: 2024/01/31 10:32:55 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_decimal(int n)
{
	ft_putnbr_fd(n, 1);
	if (n == 0)
		return (1);
	if (n < 0)
		return (ft_getsize(n) + 1);
	return (ft_getsize(n));
}
