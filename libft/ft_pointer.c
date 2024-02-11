/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:48:10 by chhoflac          #+#    #+#             */
/*   Updated: 2024/01/31 15:03:54 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getlsize(unsigned long long add)
{
	int	i;

	i = 0;
	if (add == 0)
		return (1);
	while (add != 0)
	{
		add /= 16;
		i++;
	}
	return (i);
}

int	ft_hexa_add(unsigned long long add)
{
	unsigned long long	rem;

	rem = add % 16;
	if (add >= 16)
		ft_hexa_add(add / 16);
	if (rem > 9 && rem < 16)
		ft_putchar_fd((rem + 87), 1);
	else
		ft_putchar_fd((rem + 48), 1);
	return (ft_getlsize(add));
}

int	ft_pointer(unsigned long long add)
{
	if (add == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	return (ft_hexa_add(add) + 2);
}
