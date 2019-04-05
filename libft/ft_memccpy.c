/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmills <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:44:15 by kmills            #+#    #+#             */
/*   Updated: 2018/11/28 20:44:17 by kmills           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*sour;

	dest = (unsigned char *)dst;
	sour = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest[i] = sour[i];
		if (sour[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
