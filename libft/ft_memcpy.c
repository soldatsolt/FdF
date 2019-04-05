/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:44:37 by kmills            #+#    #+#             */
/*   Updated: 2018/11/28 20:44:39 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sour;

	dest = (unsigned char *)dst;
	sour = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*dest = *sour;
		i++;
		dest++;
		sour++;
	}
	return (dst);
}
