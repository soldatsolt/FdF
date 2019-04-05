/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:50:50 by kmills            #+#    #+#             */
/*   Updated: 2018/11/28 20:50:51 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bv;

	bv = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		bv[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
