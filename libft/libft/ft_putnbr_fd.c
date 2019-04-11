/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:47:39 by kmills            #+#    #+#             */
/*   Updated: 2018/11/28 20:47:41 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	m;
	long	nb;

	nb = n;
	m = 1;
	if (nb < 0)
	{
		nb = nb * (-1);
		ft_putchar_fd('-', fd);
	}
	while (nb / (m * 10) > 0)
		m = m * 10;
	while (m > 0)
	{
		ft_putchar_fd((nb / m + '0'), fd);
		nb = nb % m;
		m = m / 10;
	}
}
