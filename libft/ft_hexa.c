/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:51:05 by chhoflac          #+#    #+#             */
/*   Updated: 2024/01/31 10:33:19 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getusize2(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_hexa_up(unsigned int n)
{
	int	rem;

	rem = n % 16;
	if (n >= 16)
		ft_hexa_up(n / 16);
	if (rem > 9 && rem < 16)
		ft_putchar_fd((rem + 55), 1);
	else
		ft_putchar_fd((rem + 48), 1);
	return (ft_getusize2(n));
}

int	ft_hexa_low(unsigned int n)
{
	int	rem;

	rem = n % 16;
	if (n >= 16)
		ft_hexa_low(n / 16);
	if (rem > 9 && rem < 16)
		ft_putchar_fd((rem + 87), 1);
	else
		ft_putchar_fd((rem + 48), 1);
	return (ft_getusize2(n));
}
